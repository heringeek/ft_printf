/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:10:55 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/30 14:10:47 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned int	ft_putnbr_base16(unsigned long n, char format, t_flags *flags)
{
	char			*base;
	unsigned int	len;

	len = 0;
	if (format == 'x')
	{
		if (flags->hash == 1 && n != 0)
		{
			len = ft_putstr_count("0x");
			flags->hash = 0;
		}
		base = "0123456789abcdef";
	}
	if (format == 'X')
	{
		if (flags->hash == 1 && n != 0)
		{
			len = ft_putstr_count("0X");
			flags->hash = 0;
		}
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
		len += ft_putnbr_base16(n / 16, format, flags);
	len += ft_putchar(base[n % 16]);
	return (len);
}
