# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 16:41:46 by ttridon           #+#    #+#              #
#    Updated: 2017/02/11 19:12:57 by baalbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L/usr/local/lib/ -I/usr/local/include
MLX_FLAGS2 = -lmlx -framework OpenGL -framework AppKit

SRC_NAME =	parsing.c draw.c \
			tool.c gnl.c \
			tool2.c fdf.c

SRC_PATH = srcs/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MLX_FLAGS2)  $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
