# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/17 18:45:16 by tbalea            #+#    #+#              #
#    Updated: 2014/01/18 21:40:20 by tbalea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D

FPE = -pedantic

FLG = -Wall -Werror -Wextra -lmlx  -lXext -lX11 -L/usr/X11/lib

SRC = main.c\
	  screen.c\
	  option.c\
	  moving.c\
	  misc.c

OBJ = $(SRC.c = .o)

OBD = $(addprefix bjt/, $(OBJ))

SRD = $(addprefix src/, $(SRC))

all : $(NAME)

$(NAME):
	gcc $(FPE) $(FLG) $(SRD) -o $(NAME)

clean:
	rm -f $(OBD)$(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
