#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/17 06:32:32 by mde-jesu          #+#    #+#              #
#    Updated: 2014/05/17 06:32:34 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = wolf3d

SRC = main.c \
	damages.c \
	end.c \
	some_calc.c \
	some_checks.c \
	some_draw_sht.c \
	some_gather.c \
	some_hooks.c \
	some_move.c \
	some_move2.c \
	some_world.c \
	sort_colors.c \
	sprcstfloor.c \
	sprite_cast.c \
	teleport_bis.c \
	sprite_cast2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ./libft/includes -I /usr/X11/include -I./ -O3

LDFLAGS = -L./libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -L /usr/lib -lm

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

lib:
	@(cd libft && $(MAKE))

clnlib:
	@(cd libft && $(MAKE) clean)

fclnlib:
	@(cd libft && $(MAKE) fclean)

clean: clnlib
	@/bin/rm -f $(OBJ)

fclean: clean fclnlib
	@/bin/rm -f $(NAME)

re: fclean all
