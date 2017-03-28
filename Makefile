# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esantos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 18:15:50 by esantos           #+#    #+#              #
#    Updated: 2016/11/05 16:08:04 by esantos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAG =  -Wall -Werror -Wextra -o $(NAME)
SRC_NAME = main.c \
		   arrange.c \
		   check.c \
		   ft_tabfill.c \
		   get.c \
		   solve.c \
		   extend.c \
		   ft_isalpha.c \
		   ft_memalloc.c \
		   ft_putchar.c \
		   ft_putendl.c \
		   ft_putstr.c \
		   ft_strdel.c \
		   ft_strsplit.c \
		   ft_strlen.c \
		   ft_strsub.c \
		   ft_strncpy.c \

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC_NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

