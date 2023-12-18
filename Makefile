# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:45:45 by picatrai          #+#    #+#              #
#    Updated: 2023/11/13 17:21:52 by picatrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putnbr_base_unsigned.c ft_putnbr_base_void.c \
ft_putnbr_base.c ft_putstr.c ft_strlen.c ft_putnbr_base_hexa_min.c \
ft_putnbr_base_hexa_maj.c
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEAD = ft_printf.h

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
