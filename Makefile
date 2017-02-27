# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 00:57:13 by opettex-          #+#    #+#              #
#    Updated: 2016/04/19 13:36:30 by opettex-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =   src/fdf.c \
		src/fdf_move.c \
	 	src/main.c \
		src/error.c \
		src/trace_segment.c \
		src/create_and_fill_tab.c

INC = -I ./include -I ./minilibx_macos

LIB = libft/libft.a
LIB_PATH = libft/

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

MLX_FLAG = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC)  $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC) $(MLX_FLAG)
	@echo "fdf created"

%.o: %.c
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

.PHONY: clean fclean re all

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)
	@echo "fdf cleaned"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@echo "fdf deleted"

re: fclean all
