# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 23:03:51 by dramos-p          #+#    #+#              #
#    Updated: 2022/01/18 22:56:00 by dramos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	libft/libft.a
GNL			=	gnl/get_next_line.a
INC			=	-I ./inc -I ./gnl -I ./libft -I ./mlx_linux
LIB			=	-L ./gnl -L ./libft -lft -L ./mlx_linux -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c \
				src/util_win.c\
				src/util_map.c\
				src/util_check.c\
				src/ft_lst.c\
				src/util_draw.c\

all:		$(GNL) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(MLX)
			$(CC) $(FLAGS) -o $@ $^ $(GNL) $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx_linux
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

$(GNL):		
			@echo " [ .. ] | Compiling GNL.."
			@make -s -C gnl
			@echo " [ OK ] | GNL ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@make -s $@ -C gnl
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@make -s $@ -C gnl
			rm -rf ${NAME}
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
