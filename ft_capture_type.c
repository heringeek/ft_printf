/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:12:48 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/30 18:41:06 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned int	ft_capture_type(const char *format, va_list args, t_flags *flags)
{
	t_flags	flag;

	flag = *flags;
	while (*format == '#' || *format == '+' || *format == ' ')
		format++;
	if (*format == 'd' || *format == 'i')
	{	
		flags->d = 1;
		return (ft_decimal(va_arg(args, int), flags));
	}
	if (*format == 'c')
		(ft_putchar_fd(va_arg(args, int), 1));
	if (*format == 's')
		return (ft_putstr_count(va_arg(args, char *)));
	if (*format == 'x' || *format == 'X')
		return (ft_putnbr_base16(va_arg(args, unsigned int), *format, flags));
	if (*format == 'u')
	{	
		flags->u = 1;
		return (ft_decimal(va_arg(args, unsigned int), flags));
	}
	if (*format == 'p')
		return (ft_ptr(va_arg(args, void *), flags));
	if (*format == '%')
		ft_print_percent_sign();
	return (1);
}
