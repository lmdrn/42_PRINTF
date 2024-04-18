/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:26 by lmedrano          #+#    #+#             */
/*   Updated: 2022/11/06 19:19:54 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_fmt(char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printchar(va_arg(ap, int));
	else if (format == 's')
		len = ft_printstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		len = ft_printnbr(va_arg(ap, int));
	else if (format == 'x' || format == 'X')
		len = ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		len = ft_printptr(va_arg(ap, unsigned long long));
	}
	else if (format == 'u')
		len = ft_printuint(va_arg(ap, unsigned int));
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_check_fmt(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
