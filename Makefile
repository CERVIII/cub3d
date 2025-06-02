# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:06:04 by pcervill          #+#    #+#              #
#    Updated: 2025/06/02 21:36:24 by mpenas-z         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME = cub3D
BONUS_NAME = cub3D_bonus
CC = cc
CFLAGS =	-Wall -Werror -Wextra -I ./include -I ./libft -I $(MLX_DIR) \
			-g -g3 -fsanitize=address
RM = rm -f

SRC_SRC =	main.c utils.c free_utils.c
BSRC_SRC =	main_bonus.c utils.c free_utils.c
PRS_SRC =	parser.c parser_file.c parser_texture.c parser_map.c parser_check.c
BPRS_SRC =	parser_bonus.c parser_file_bonus.c parser_texture_bonus.c \
			parser_map_bonus.c parser_check_bonus.c
GME_SRC =	game.c map2d.c events.c player.c \
			raycasting.c texture.c extra.c
BGME_SRC =	game_bonus.c map2d_bonus.c events_bonus.c player_bonus.c \
			raycasting_bonus.c texture_bonus.c extra_bonus.c \
			torch_bonus.c torch_extra_bonus.c

ifeq ($(UNAME),Darwin)
	MLX_DIR = ./minilibx_opengl/minilibx_opengl_20191021/
	MLX_PATH =	${MLX_DIR}/libmlx.a
	MFLAGS = -L $(MLX_DIR) $(MLX_DIR)libmlx.a -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR =	./minilibx-linux
	MLX_PATH =	${MLX_DIR}/libmlx.a
	MFLAGS =	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

SRC = $(SRC_SRC) $(PRS_SRC) $(GME_SRC)
BONUS_SRC = $(BSRC_SRC) $(BPRS_SRC) $(BGME_SRC)

INCLUDES = ./include/cub3d.h ./include/parser.h ./include/game.h \
		   ./libft/libft.h ./include/game_bonus.h \
		   ./include/cub3d_bonus.h ./include/parser_bonus.h
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = ./src/
BSRC_DIR = ./src/
PRS_DIR = $(SRC_DIR)parser/
BPRS_DIR = $(SRC_DIR)parser_bonus/
GME_DIR = $(SRC_DIR)game/
BGME_DIR = $(SRC_DIR)game_bonus/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
BOBJ_FILES = $(BONUS_SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
BOBJ = $(addprefix $(OBJ_DIR), $(BOBJ_FILES))

# RULES
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)
	@echo " \033[36m[ 🕹️  ] | READY TO PLAY!\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Objects for Main
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Bonus Main
$(OBJ_DIR)%.o: $(BSRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Parser
$(OBJ_DIR)%.o: $(PRS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Bonus Parser
$(OBJ_DIR)%.o: $(BPRS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Game
$(OBJ_DIR)%.o: $(GME_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for BONUS
$(OBJ_DIR)%.o: $(BGME_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX_PATH):
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo " \033[32m[ OK ] | ✅ Minilibx ready! ✅\033[0m"

# LIBFT
$(LIBFT):
	@make -C $(LIBFT_DIR) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"

# basic library compiled
$(NAME): $(LIBFT) $(MLX_PATH) $(OBJ)
	@echo " \033[33m[ .. ] | Compiling $(NAME)... \033[0m"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MFLAGS)
	@echo " \033[32m[ OK ] | ✅ $(NAME) ready! ✅\033[0m"

# bonus compiled
bonus: $(OBJ_DIR) $(LIBFT_DIR) $(BONUS_NAME)
	@echo " \033[36m[ 🕹️  ] | READY TO PLAY!\033[0m"

$(BONUS_NAME): $(LIBFT) $(MLX_PATH) $(BOBJ)
	@echo " \033[33m[ .. ] | Compiling $(NAME) BONUS... \033[0m"
	@$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o cub3D $(MFLAGS)
	@echo " \033[32m[ OK ] | ✅ $(NAME) ready! ✅\033[0m"

# all .o files removed
clean:
	@$(RM) $(OBJ) $(BOBJ)
	@make clean -C libft --silent
	@rm -rf $(OBJ_DIR)

# library .a file removed
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft --silent
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MLX_DIR) > /dev/null 2>&1
	@echo " \033[35m[ OK ] | 🧹 $(NAME)! 🧹\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
