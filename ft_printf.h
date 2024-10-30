/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:20 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/30 18:38:01 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct flags {
	unsigned int	u;
	void			*ptr;
	char			*string;
	char			c;
	char			percent;
	int				i;
	int				d;
	int				x_lower;
	int				x_upper;
	int				hash;
	int				plus;
	int				space;
}	t_flags;

unsigned int	ft_putchar(int c);
unsigned int	ft_print_percent_sign(void);
unsigned int	ft_putnbr_base16(unsigned long n, char format, t_flags *flags);
unsigned int	ft_capture_type(const char *format, va_list args, t_flags *flags); //cap
unsigned int	ft_decimal(unsigned int arg, t_flags *flags);
unsigned int	ft_ptr(void *ptr, t_flags *flags);
unsigned int	ft_putstr_count(char *s);
unsigned int	ft_putstr_aux(char *s);
unsigned int	ft_decimal(unsigned int arg, t_flags *flags);
void			ft_putnbr_fd(int n, int fd);
void			ft_init_flags(t_flags *flags);
void			ft_check_flag_bonus(const char *format, t_flags *flags);
char			*ft_utoa(unsigned int n);
int				ft_printf(const char *format, ...);

#endif