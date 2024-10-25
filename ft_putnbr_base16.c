/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:10:55 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/25 18:34:25 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	ft_putnbr_base16(unsigned long n, char c)
{
	if (c == 'x')
	{
		if (n >= 16)
			ft_putnbr_base16(n / 16, c);
		if ((n%16) < 10)
			ft_putchar_fd((n % 16) + '0', 1);
		else
			ft_putchar_fd((n % 16) - 10 + 'a', 1);
	}
	else 
	{
		if (n >= 16)
			ft_putnbr_base16(n / 16, c);
		if ((n%16) < 10)
			ft_putchar_fd((n % 16) + '0', 1);
		else
			ft_putchar_fd((n % 16) - 10 + 'A', 1);
	}
}