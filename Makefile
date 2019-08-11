# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlarson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 19:13:22 by hlarson           #+#    #+#              #
#    Updated: 2019/08/11 19:39:07 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c init.c help_init.c

OUT = main.o init.o help_init.o

LIB = libft.a
LIB_PATH = lib/

MINILIBX_PATH = minilibx_macos/

MLX_ADD = -L minilibx_macos -lmlx -framework OpenGL	-framework Appkit

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	make -C $(MINILIBX_PATH)
	gcc -Wall -Wextra -Werror $(SRCS) $(LIB_PATH)$(LIB) $(MLX_ADD) -o $(NAME)

clean:
	@$(MAKE) -sC $(LIB_PATH) clean
	@$(MAKE) -sC $(MINILIBX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_PATH)$(LIB)
	rm -rf $(MINILIBX_PATH)libmlx.a

re: fclean all
