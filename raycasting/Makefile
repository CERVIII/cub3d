# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 11:18:46 by pcervill          #+#    #+#              #
#    Updated: 2024/10/29 14:13:15 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raycasting
CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./include -I $(MLX_DIR)
OBJ = $(SRC:.c=.o)

ifeq ($(UNAME),Darwin)
	MLX_DIR = ../minilibx_opengl/minilibx_opengl_20191021/
	MFLAGS = -L $(MLX_DIR) $(MLX_DIR)libmlx.a -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR =	../minilibx-linux
	MLX_PATH =	${MLX_DIR}/libmlx.a
	MFLAGS =	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

INCLUDES = ./include/raycasting.h $(MLX_DIR)/mlx.h
SRC = ./raycasting.c ./player.c ./draw_px.c

all: $(NAME)

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