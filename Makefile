#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 18:01:32 by mde-jesu          #+#    #+#              #
#    Updated: 2014/01/15 18:03:57 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
SRC = main.c \
		wolf.c

SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes -I./libft/includes
LIB_CALL = -L./libft \
		`SDL2/bin/sdl2-config --libs`

CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -pedantic-errors
CFLAGS += `SDL2/bin/sdl2-config --cflags`

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

all: $(SLD2) $(LIBFT) $(OBJDIR) $(NAME)

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

SDL2:
	mkdir -p SDL2/junk
	wget http://www.libsdl.org/release/SDL2-2.0.1.tar.gz
	tar xf SDL2-2.0.1.tar.gz
	( cd SDL2-2.0.1 \
		&& ./configure --prefix=$(shell pwd)/SDL2/ \
		&& $(MAKE) all \
		&& $(MAKE) install )
	mv SDL2-2.0.1.tar.gz SDL2-2.0.1 SDL2/junk

.PHONY: clean fclean re all clean-ft fclean-ft re-ft
