/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:10:19 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/30 18:39:28 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned int	ft_decimal(unsigned int arg, t_flags *flags)
{
	char				*convert_to_alpha;
	unsigned int		len;

	len = 0;
	if (flags->u)
		convert_to_alpha = ft_utoa(arg);
	else
		convert_to_alpha = ft_itoa(arg);
	if (flags->plus == 1 || flags->space == 1)
	{
		int	j;

		j = 0;
		if (convert_to_alpha[j] == '-')
		{
		}
		else if (flags->plus == 1)
		{
			ft_putchar('+');
			len = 1;
		}
		else
		{
			ft_putchar(' ');
			len = 1;
		}
	}
	ft_putstr_count(convert_to_alpha);
	len += ft_strlen(convert_to_alpha);
	free(convert_to_alpha);
	return (len);
}
