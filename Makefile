# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 01:35:02 by dramos-p          #+#    #+#              #
#    Updated: 2022/01/04 23:58:48 by dramos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
# MLX = -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX = -L ./mlx_linux -lmlx -lXext -lX11

SRC = teste3.c
OBJ = $(SRC:.c=.o)

MLX_DIR = mlx_linux
SRC_DIR = src

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS        = $(addprefix $(SRC_DIR)/, $(OBJ))

INCUDE = -I inc

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(MLX) -o $(NAME)

clean :
	rm -f $(OBJS) $(NAME)

fclean : clean
	rm -f $(NAME) $(NAME)

re : fclean all