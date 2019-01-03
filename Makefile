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
OBJS = *.o
SRC = *.c
LIB = @make -C libft/

all: $(NAME)

$(NAME):
	$(LIB)
	@gcc -Wall -Wextra -Werror -o ft_printf $(SRC) ./libft/libft.a -I./ -I./libft/

clean:
	@$(LIB) clean
	@rm -f ft_printf
	@rm -f $(OBJS)
	@rm -f *.c~
	@rm -f *.c~
	@rm -f *~

fclean: clean
	@$(LIB) fclean
	@rm -f $(NAME)

re: fclean all

