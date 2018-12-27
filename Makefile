#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 15:28:53 by dpiven            #+#    #+#              #
#    Updated: 2018/11/10 16:53:53 by dpiven           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
OBJS = *.o
SRC = *.c

all: $(NAME)

$(NAME):
	@gcc -c $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJS)
	@gcc -o ft_printf $(SRC)

clean:
	@rm -f $(OBJS)
	@rm -f *.c~
	@rm -f *.c~
	@rm -f *~

fclean: clean
	@rm -f $(NAME)

re: fclean all

