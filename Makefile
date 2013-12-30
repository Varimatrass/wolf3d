#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 18:01:32 by mde-jesu          #+#    #+#              #
#    Updated: 2013/12/30 23:44:17 by mde-jesu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1
DEBUG = yes
LD = $(CC)
SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = -I./includes -I./libft/includes -I/usr/X11/include/
LIB_CALL = -L./libft -lft -L./usr/X11/lib -lmlx -lXext -lX11

ifeq ($(DEBUG),yes)
	CC = clang
	CFLAGS = -fstack-protector-all -Wshadow -Wall -Werror -Wextra \
		-Wunreachable-code -Wstack-protector -pedantic-errors \
		-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes \
		-Wwrite-strings -Wunreachable-code -pedantic \
		-Wunknown-pragmas -Wdeclaration-after-statement \
		-Wold-style-definition -Wmissing-field-initializers \
		-Winline -g -W
else
	CC = gcc
	CFLAGS= -Wall -Wextra -Werror -O3
endif

LDFLAGS = $(CFLAGS)
SRC = main.c \
	ft_sh1.c \
	use_fork.c \
	ft_builtins.c \
	ft_env.c

OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_PREF)
	@make -C ./libft
	@$(LD) -o $@ $^ $(LDFLAGS) $(INCDIR) $(LIB_CALL)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@make -C libft clean
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)
	@rm ./libft/libft.a

re: fclean all


.PHONY: clean fclean re all
