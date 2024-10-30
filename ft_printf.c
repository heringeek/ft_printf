/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:47:34 by rheringe          #+#    #+#             */
/*   Updated: 2024/10/30 19:18:58 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	unsigned int	count_chars;
	va_list			args;
	t_flags			flags;

	va_start(args, format);
	count_chars = 0;
	if (!format)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	while (*format)
	{
		if (!ft_strchr("cspdiuxX%", *format))
			count_chars += ft_putchar(*format);
		else if (*format == '%')
		{
			ft_init_flags(&flags);
			format++;
			ft_check_flag_bonus(format, &flags);
			count_chars += ft_capture_type(format, args, &flags);
		}
		format++;
	}
	va_end(args);
	return (count_chars);
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
	flags->ptr = NULL;
	flags->string = NULL;
	flags->c = 0;
	flags->percent = 0;
	flags->i = 0;
	flags->d = 0;
	flags->x_lower = 0;
	flags->x_upper = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

unsigned int	ft_ptr(void *ptr, t_flags *flags)
{
	unsigned int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len += ft_putstr_count("0x");
	len += ft_putnbr_base16((unsigned long)ptr, 'x', flags);
	return (len);
}

// int main()
// {
// 	printf("%d\n" ,ft_printf(" % d\n" ,9));
// 	printf("%d\n" ,printf(" % d\n" ,9));
// 	return (0);
// }


//cc ft_capture_type.c  ft_printf.c  ft_print_percent_sign.c  ft_putnbr_base16.c  ft_utoa.c ft_decimal.c       ft_printf.h  ft_putchar.c             ft_putstr_count.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_itoa.c libft/ft_strlen.c  libft/ft_strchr.c libft/libft.h

// void printcmp(int a, int b)
// {
//     if (a == b)
//     {
//         ft_printf("OK\n");
//     }
//     else
//         ft_printf("KO --!\n");
// }

// int main(void)
// {
//     char    *str = "12ozmouse";
//     char    *nulo = NULL;
//     char    **ptr;
//     int     myfunc;
//     int     original;
//     ptr = &str;

//     ft_printf("---------my func-----------\n");
//     myfunc = ft_printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);
    
//     ft_printf("\n---------original-----------\n");
// 		original = printf("c flag: %c|%c|%c|%c|%c\n", 'r', str[2], 97 - 32, *str, 48);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse", str, str + 2, "", "-", nulo);
    
//     ft_printf("\n---------original-----------\n");
//     original = printf("s flag: %s|%s|%s|%s|%s|%s\n", "12ozmouse", str, str + 2, "", "-", nulo);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);
    
//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, nulo, &nulo);

//     ft_printf("\n---------original-----------\n");
//     original = printf("p flag: %p|%p|%p|%p|%p|%p\n", str, &str, ptr, &ptr, nulo, &nulo);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483648);

//     ft_printf("\n---------original-----------\n");
//     original = printf("d flag: %d|%d|%d|%d|%d\n", 7, -7, 0, 2147483647, -2147483647 - 1);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483648);

//     ft_printf("\n---------original-----------\n");
//     original = printf("i flag: %i|%i|%i|%i|%i\n", 7, -7, 0, 2147483647, -2147483647 - 1);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0, 2147483647, -2147483648);

//     ft_printf("\n---------original-----------\n");
//     original = printf("u flag: %u|%u|%u|%u|%u\n", 7, -7, 0, 2147483647, -2147483647 - 1);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483648);

//     ft_printf("\n---------original-----------\n");
//     original = printf("x flag: %x|%x|%x|%x|%x\n", 7, -7, 0, 2147483647, -2147483647 - 1);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483648);

//     ft_printf("\n---------original-----------\n");
//     original = printf("X flag: %X|%X|%X|%X|%X\n", 7, -7, 0, 2147483647, -2147483647 - 1);

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("%% flag: %% | %%|%% \n");

//     ft_printf("\n---------original-----------\n");
//     original = printf("%% flag: %% | %%|%% \n");

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf(", I've printed %d characters!\n",
//      ft_printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

//     ft_printf("\n---------original-----------\n");
//     original = printf(", I've printed %d characters!\n",
//      printf("d flag: %d|%d|%d|%d", 0, -37, 37, 187398217));

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf(", I've printed %d characters!\n",
//      ft_printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

//     ft_printf("\n---------original-----------\n");
//     original = printf(", I've printed %d characters!\n",
//      printf("d flag: %d|%d|%d|%d", 0, -22222, 'n', 0));

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf(", I've printed %d characters!\n",
//      ft_printf("INT MIN: %d", -2147483647 - 1));

//     ft_printf("\n---------original-----------\n");
//     original = printf(", I've printed %d characters!\n",
//      printf("INT MIN: %d", -2147483647 - 1));

//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], nulo, str, -912387, 00000, -99, 743, 743);

//     ft_printf("\n---------original-----------\n");
//     original = printf("MIXED:%c|%s|%p|%d|%i|%u|%x|%X|%%\n", str[6], nulo, str, -912387, 00000, -99, 743, 743);
    
//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);


//     ft_printf("\n---------my func-----------\n");
//     myfunc = ft_printf(NULL);
//     ft_printf("\n---------original-----------\n");
//     original = printf(NULL);
    
//     ft_printf("\n---------resultado-----------\n");
//     printcmp(myfunc, original);

// }