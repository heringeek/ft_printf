/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:49:22 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/01 15:59:27 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned int	ft_putstr_count(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_putnbr_base16(unsigned long n, char format, t_flags *flags)
{
	char			*base;
	unsigned int	len;

	len = 0;
	if (format == 'x')
	{
		if (flags->hash == 1 && n != 0)
			len = ft_putstr_count("0x");
		base = "0123456789abcdef";
	}
	if (format == 'X')
	{
		if (flags->hash == 1 && n != 0)
			len = ft_putstr_count("0X");
		base = "0123456789ABCDEF";
	}
	flags->hash = 0;
	if (n >= 16)
		len += ft_putnbr_base16(n / 16, format, flags);
	len += ft_putchar(base[n % 16]);
	return (len);
}

unsigned int	ft_print_percent_sign(void)
{
	return ((write(1, "%", 1)));
}

unsigned int	ft_ptr(void *ptr, t_flags *flags)
{
	unsigned int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	len += ft_putstr_count("0x");
	len += ft_putnbr_base16((unsigned long)ptr, 'x', flags);
	return (len);
}