/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:47:34 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:58 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_putnbr_base16(unsigned long n, char c);
unsigned int  ft_capture_type(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else 
		{
			i += ft_capture_type(&format[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}

unsigned int  ft_capture_type(const char *format, va_list args)
{
	void	*ptr;
	ptr = va_arg(args, void *);
	unsigned int	i;
	char			index;
	i = 0;
	i++;
	index =  format[i];
	if (index == 'd' || index == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
		return (1);
	if (index == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	if (index == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (index == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (index == 'x' || index == 'X')
		ft_putnbr_base16(va_arg(args, int), index);
	if (index == '%')
		ft_print_percent_sign();
	if (index == 'p')
		ft_putnbr_base16((unsigned long)ptr, index);
	return (1);
}

int main ()
{
	char *ptr;
	ptr = NULL;
	ft_printf("any random thing her  withe name %s more num I: %i%% decimal %x decimal UP: %X UNSIGNED -: %u UNSIGNED +: %u Ptr: %p\n", "42sp", 30, 42, 42, -42, 42, &ptr);
	printf("any random thing her  withe name %s more num I: %i%% decimal %x decimal UP: %X UNSIGNED -: %u UNSIGNED +: %u Ptr: %p\n", "42sp", 30, 42, 42, -42, 42, &ptr);
	return (0);
}
