# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 13:32:13 by sbriggs           #+#    #+#              #
#    Updated: 2018/08/13 11:37:56 by sbriggs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c \
		pr_bzero.c \
		pr_format.c \
		pr_itoa_base.c \
		pr_putaddr.c \
		pr_putchar.c \
		pr_putstr.c \
		pr_putstr_case.c \
		pr_strchr.c \
		pr_tolower.c \
		pr_toupper.c \

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Werror -Wextra -c $(FILES)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

run: re
	gcc main.c libftprintf.a
	./a.out
