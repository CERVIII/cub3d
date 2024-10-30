# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 11:18:46 by pcervill          #+#    #+#              #
#    Updated: 2024/10/30 13:58:36 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME = raycasting
CC = gcc
OBJ = $(SRC:.c=.o)

ifeq ($(UNAME),Darwin)
	MLX_DIR = ../minilibx_opengl/minilibx_opengl_20191021/
	MFLAGS = -L $(MLX_DIR) $(MLX_DIR)libmlx.a -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR =	../minilibx-linux
	MLX_PATH =	${MLX_DIR}/libmlx.a
	MFLAGS =	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

CFLAGS = -Wall -Werror -Wextra -I ./include -I $(MLX_DIR)
INCLUDES = ./include/raycasting.h $(MLX_DIR)/mlx.h
SRC = ./raycasting.c ./player.c ./draw_px.c ./game.c

all: $(NAME)
	@echo " \033[36m[ 🕹️  ] | READY TO PLAY!\033[0m"

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	@echo " \033[32m[ OK ] | ✅ Minilibx ready! ✅\033[0m"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MFLAGS)

fclean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ)
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re