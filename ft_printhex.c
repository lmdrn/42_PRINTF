/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:54:57 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 19:37:25 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_puthex(unsigned int hex, char format)
{
	if (hex >= 16)
	{
		ft_puthex((hex / 16), format);
		ft_puthex((hex % 16), format);
	}
	else
	{
		if (hex <= 9)
			ft_printchar(hex + 48);
		else
		{
			if (format == 'x')
				ft_printchar(hex - 10 + 'a');
			if (format == 'X')
				ft_printchar(hex - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int hex, char format)
{
	int	len;

	len = 0;
	if (hex == 0)
		len += write(1, "0", 1);
	else
	{
		ft_puthex(hex, format);
		len += ft_hexlen(hex);
	}
	return (len);
}
