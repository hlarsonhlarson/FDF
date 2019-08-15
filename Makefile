# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlarson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 19:13:22 by hlarson           #+#    #+#              #
#    Updated: 2019/08/15 14:30:17 by hlarson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c init.c help_init.c ft_check_num_and_color.c ft_exit_error.c
SRCS += ft_make_op.c draw_line.c draw.c

OUT = main.o init.o help_init.o ft_check_num_and_color.o ft_exit_error.o ft_make_op.o draw_line.o draw.o

LIB = libft.a
LIB_PATH = lib/

MINILIBX_PATH = minilibx_macos/

MLX_ADD = -L minilibx_macos -lmlx -framework OpenGL	-framework Appkit

INCLUDES = libft.h

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	make -C $(MINILIBX_PATH)
	gcc -Wall -Wextra -Werror $(SRCS) $(LIB_PATH)$(LIB) $(MLX_ADD) -g -o $(NAME)

clean:
	@$(MAKE) -sC $(LIB_PATH) clean
	@$(MAKE) -sC $(MINILIBX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_PATH)$(LIB)
	rm -rf $(MINILIBX_PATH)libmlx.a

re: fclean all
