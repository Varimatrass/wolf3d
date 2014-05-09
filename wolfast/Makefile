#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 18:01:32 by mde-jesu          #+#    #+#              #
#    Updated: 2014/05/09 14:00:18 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

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

SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes -I./libft/includes
INCDIR += -I /usr/X11/include
LIB_CALL = -L./libft -lft
LIB_CALL += -L/usr/X11/lib -lmlx -lXext -lX11
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -pedantic-errors

ifeq ($(W),)
	CC = gcc
	CFLAGS += -O3
else
	CC = clang
	CFLAGS +=	-ggdb3 -fstack-protector-all -Wshadow -Wunreachable-code \
				-Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
				-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes -pedantic \
				-Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement\
				-Wold-style-definition -Wmissing-field-initializers -Wfloat-equal\
				-Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common\
				-Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
				-Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer
endif

LD = $(CC)

OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(LIBFT) $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(OBJS_PREF)
	@$(LD) -o $@ $^ $(LIB_CALL) $(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(LIBFT):
	@( $(MAKE) all -C ./libft)

clean-ft:
	@( $(MAKE) clean -C ./libft )

fclean-ft:
	@( $(MAKE) fclean -C ./libft )

re-ft: fclean-ft $(LIBFT)

.PHONY: clean fclean re all clean-ft fclean-ft re-ft
