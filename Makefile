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
CFLAGS = -Wall -Wextra -Werror -std=c99

SRC_FILES = *.c
LIB = @make -C libft/ fclean && make -C libft/
#LIBFT_FILES = *.c
#LIB_DIR = libft/
#SRC_DIR = ./
#INC = -Iincludes/
#LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))
#OBJ = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

all: $(NAME)

$(NAME):
	$(LIB)
#	@gcc -c $(CFLAGS) $(SRC) $(LIBFT) $(INC)
#	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)
	@gcc -Wall -Wextra -Werror -o ft_printf $(SRC) ./libft/libft.a -I./ -I./libft/

clean:
	@$(LIB) clean
	@rm -f ft_printf
	@rm -f $(OBJS)
	@rm -f *.c~
	@rm -f *.o
	@rm -f *~

fclean: clean
	@$(LIB) fclean
	@rm -f $(NAME)

re: fclean all

