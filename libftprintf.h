/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:20 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/25 18:49:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_index_list {
	unsigned int	u;
	void			*ptr;
	char			*string;
	char			c;
	char			percent;
	int				i;
	int				d;
	int				x_lower;
	int				x_upper;
}	t_index_list;

unsigned int	ft_putchar(int c);
unsigned int	ft_print_percent_sign(void);
void			ft_putnbr_fd(int n, int fd);
int				ft_printf(const char *format, ...);
void	ft_putnbr_base16(unsigned long n, char c);

#endif