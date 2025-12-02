/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-ju <jdias-ju@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:43:14 by jdias-ju          #+#    #+#             */
/*   Updated: 2025/12/02 11:29:20 by jdias-ju         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_conversion(const char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if ((type == 'X') || (type == 'x'))
		return (ft_putnbr_hexa(va_arg(arg, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		check;
	
	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_conversion(*(++format), arg);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}	
	va_end(arg);
	return (len);
}
