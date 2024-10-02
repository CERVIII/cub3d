# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:06:04 by pcervill          #+#    #+#              #
#    Updated: 2024/10/02 13:51:01 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS =	-Wall -Werror -Wextra -I ./include -I ./libft -I $(MLX_DIR) \
			#-g -g3 -fsanitize=address

RM = rm -f

SRC_SRC =	main.c utils.c
PRS_SRC =	arg.c
GME_SRC =	

ifeq ($(UNAME),Darwin)
	MLX_DIR = ./minilibx_opengl/
	MFLAGS:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR =	./minilibx-linux
	MLX_PATH =	${MLX_DIR}/libmlx.a
	#MFLAGS =	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
endif

SRC = $(SRC_SRC) $(PRS_SRC) $(GME_SRC)

INCLUDES = ./include/cub3d.h ./libft/libft.h
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = ./src/
PRS_DIR = $(SRC_DIR)parser/
GME_DIR = $(SRC_DIR)game/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# RULES
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Objects for Main
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Parser
$(OBJ_DIR)%.o: $(PRS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Objects for Game
$(OBJ_DIR)%.o: $(GME_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# basic library compiled
$(NAME): $(OBJ)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo " \033[32m[ OK ] | ✅ Minilibx ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
	@make -C $(LIBFT_DIR) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling $(NAME)... \033[0m"
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME) $(MFLAGS)
	@echo " \033[32m[ OK ] | ✅ $(NAME) ready! ✅\033[0m"

# all .o files removed
clean:
	@$(RM) $(OBJ)
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