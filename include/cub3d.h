/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:47:07 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/27 14:53:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_opengl/minilibx_opengl_20191021/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "parser.h"
# include "game.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define MINIMAP 0

/* # define PJ "./Sprites/Pacman_HD.xpm"
# define PJL "./Sprites/pac_semi_left.xpm"
# define PJR "./Sprites/pac_semi_right.xpm"
# define PJD "./Sprites/pac_semi_down.xpm"
# define PJU "./Sprites/pac_semi_up.xpm"
# define CO "./Sprites/coin.xpm"
# define EX "./Sprites/portal_close.xpm"
# define FL "./Sprites/floor1.xpm"
# define WL "./Sprites/wall.xpm" */

# define NORMAL  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENT  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

/* UTILS.C */
int		rgb_to_hex(int r, int g, int b);
int		get_heigh(char **map);
int		get_width(char **map);
void	init_data(t_data *data);
void	free_array(char **str);
void	free_all(t_data *data);
int		ft_error(char *error, t_data *data, char *file);

/* MAIN.C */
void	print_array(char **arr);

#endif