/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:47:34 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/01 17:30:36 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	unsigned int	count_chars;
	va_list			args;
	t_flags			flags;

	va_start(args, format);
	count_chars = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_flags(&flags);
			format++;
			ft_check_flag_bonus(format, &flags);
			count_chars += ft_cap_type(format, args, &flags);
			while (ft_strchr(" +#", *format))
				format++;
		}
		else
			count_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count_chars);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	return (NULL);
}

void	ft_check_flag_bonus(const char *format, t_flags *flags)
{
	int	count;

	count = 0;
	while (format[count] == '#' || format[count] == '+' || format[count] == ' ')
	{
		if (format[count] == '#')
			flags->hash = 1;
		if (format[count] == '+')
			flags->plus = 1;
		if (format[count] == ' ')
			flags->space = 1;
		count++;
	}
}

void	ft_init_flags(t_flags *flags)
{
	flags->u = 0;
	flags->d = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

//cc -w ft_printf_bonus.c ft_printf_bonus.h ft_printf_utils_bonus.c 
//	ft_printf_utils2_bonus.c ft_printf_utils3_bonus.c
//cc -w ft_printf.c ft_printf.h ft_printf_utils.c ft_printf_utils2.c
// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	char ch = 'A';
// 	char *str = "string";
// 	int i = -42;
// 	int j = -42;
// 	unsigned int u = 42;
//     int count;
//     count = 0;
// 	Test 1: c, s, d, i
// 	printf("Test1\n");
// 	count = ft_printf("%s  %c  %d  %i\n", str, ch, i, i);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("%s  %c  %d  %i\n", str, ch, i, i);
//     printf("printf count = %d\n\n\n", count);
// 	Test 2: p
// 	printf("Test2\n\n");
//     count = ft_printf("p: %p\n\n", str);
// 	printf("ft_printf count = %d\n\n", count);  
// 	count = printf("p: %p\n\n", str);
// 	printf("printf count = %d\n\n\n", count);  
// 	Test 3: u
// 	printf("Test3\n");
//     count = ft_printf("unsigned: %u\n", u);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("unsigned: %u\n", u);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 4: u but sending negative int
// 	printf("Test4\n");
//     count = ft_printf("unsigned: %u\n", j);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("unsigned: %u\n", j);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 5: x
// 	printf("Test5\n");
// 	count = ft_printf("hex: %x\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	ft_printf("hex: %x\n", i);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 6: X
// 	printf("Test6\n");
// 	count = ft_printf("hex: %X\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	ft_printf("hex: %X\n", i);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 7: %%
// 	printf("Test7\n");
// 	count = ft_printf("percentage %%\n");
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("percentage %%\n");
// 	printf("printf count = %d\n\n\n", count);
// 	Test 8: %j - an invalid argument
// 	printf("Test8\n");
//     count = ft_printf("f%jk\n", i);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("f%jk\n", i);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 9: s (null)
// 	printf("Test9\n");
// 	count = ft_printf(" NULL %s NULL\n", NULL);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" NULL %s NULL\n", NULL);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 10: s (sending 0)
// 	printf("Test10\n");
// 	count = ft_printf(" NULL %s NULL\n", 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" NULL %s NULL\n", 0);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 11: p (long address)
// 	(long) LONG_MAX: 2147483647  LONG_MIN: -2147483648 
// 	printf("Test11\n");
// 	count = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 12: p (unsigned long address)
// 	printf("Test12\n");
// 	count = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 13: p (nil) (sending 0)
// 	printf("Test13\n");
// 	count = ft_printf(" %p %p \n", 0, 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %p %p \n", 0, 0);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 14: hex (sending 0)
// 	printf("Test14\n");
// 	count = ft_printf(" %x %x \n", 0, 0);
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf(" %x %x \n", 0, 0);
// 	printf("printf count = %d\n\n\n", count);
// 	Test 15: with no arguments
// 	printf("Test15\n");
// 	count = ft_printf("Hi %d Hai\n");
// 	printf("ft_printf count = %d\n\n", count);
// 	count = printf("Hi %d Hai\n");
// 	printf("printf count = %d\n\n\n", count);
// 	Test 16
// 	undefined behavior, it can lead to seg fault or crash
// 	printf("Test16\n");
// 	count = printf(NULL);
// 	printf("printf count = %d\n\n", count);
// 	count = ft_printf(NULL);
// 	printf("ft_printf count = %d\n\n\n", count);
// 	Test 17
// 	printf("Test17\n");
// 	count = printf("%s\n", "");
// 	printf("printf count = %d\n", count);
// 	count = ft_printf("%s\n", "");
// 	printf("ft_printf count = %d\n\n", count);
// 	////////// BONUS //////////
// 	printf("Test0 BONUS\n");
// 	count = printf("%#x\n", 456);
// 	printf("count: %d\n", count);
// 	count = ft_printf("%#x\n", 456);
// 	printf("count: %d\n\n", count);
// 	printf("Test1 BONUS\n");
// 	count = printf("%#X\n", -456);
// 	printf("count: %d\n", count);
// 	count = ft_printf("%#X\n", -456);
// 	printf("count: %d\n\n", count);
//     printf("Test2 BONUS\n");
// 	count = printf("% d\n", 42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% d\n", 42);
// 	printf("count: %d\n\n", count);
//     printf("Test3 BONUS\n");
// 	count = printf("%+d\n", 42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("%+d\n", 42);
// 	printf("count: %d\n\n", count);
// 	printf("Test4 BONUS\n");
// 	count = printf("% +#d\n", -42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +#d\n", -42);
// 	printf("count: %d\n\n", count);
// 	printf("Test5 BONUS\n");
// 	count = printf("% +d\n", -42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +d\n", -42);
// 	printf("count: %d\n\n", count);
// 	printf("Test6 BONUS\n");
// 	count = printf("% +#x\n", 456);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +#x\n", 456);
// 	printf("count: %d\n\n", count);
// 	printf("Test7 BONUS\n");
// 	count = printf("% +#X\n", -456);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +#X\n", -456);
// 	printf("count: %d\n\n", count);
//     printf("Test8 BONUS\n");
// 	count = printf("% i\n", 42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% i\n", 42);
// 	printf("count: %d\n\n", count);
//     printf("Test9 BONUS\n");
// 	count = printf("%+i\n", 42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("%+i\n", 42);
// 	printf("count: %d\n\n", count);
// 	printf("Test10 BONUS\n");
// 	count = printf("% +#i\n", -42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +#i\n", -42);
// 	printf("count: %d\n\n", count);
// 	printf("Test11 BONUS\n");
// 	count = printf("% +i\n", -42);
// 	printf("count: %d\n", count);
// 	count = ft_printf("% +i\n", -42);
// 	printf("count: %d\n\n", count);
// }