# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 13:50:02 by vrabaib           #+#    #+#              #
#    Updated: 2019/05/01 13:55:04 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADER = display.h keys.h fdf.h

SRC = process.c utils.c utils2.c events.c draw.c main.c projection.c

SRCO = process.o utils.o utils2.o events.o draw.o main.o projection.o

LIB = libft/libft.a

GL = -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Werror -Wextra -c $(SRC) -I libft/includes
	clang $(GL) $(SRCO) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -rf $(SRCO)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean 
