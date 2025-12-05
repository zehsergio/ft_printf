/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-ju <jdias-ju@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:04:37 by jdias-ju          #+#    #+#             */
/*   Updated: 2025/12/05 11:12:47 by jdias-ju         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nb)
{
	char		c;
	int			len; 
	int			aux;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		aux = ft_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	c = nb % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char up)
{
	int		len;
	int		mod;
	char	*base;
	int		aux;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		aux = ft_putnbr_hexa((nbr / 16), up);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	mod = nbr % 16;
	if (write(1, &base[mod], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}

int	ft_putstr(char *str1)
{
	int	len;

	if (!str1)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str1 != '\0')
	{
		if (write(1, str1, 1) == -1)
			return (-1);
		len++;
		str1++;
	}
	return (len);
}
