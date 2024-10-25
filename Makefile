# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:38:28 by rheringe          #+#    #+#              #
#    Updated: 2024/10/25 16:35:10 by rheringe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_putchar.c \
				ft_print_percent_sign.c \
				ft_printf.c \
				ft_putnbr_base16.c

HEADER		=	-Ilibft \
				-I.

LIBFT_DIR	=	../libft
LIBFT		=	$(LIBFT_DIR)/libft.a

AR			=	ar rcs

RM			=	rm -rf

OBJS		=	${SRCS:.c=.o}

all: ${NAME}

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${HEADER} -o ${NAME}

bonus: ${OBJS_BONUS}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	@${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	${RM} ${NAME}
	@${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re bonus
