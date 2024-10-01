/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:47:07 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/01 15:13:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_opengl/minilibx_opengl_20191021/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

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

# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define UP 126
# define ESC 53

/* ERROR */
# define ERR_ARG "Not valid arguments\n"
# define ERR_NAME "The name is very short"
# define ERR_EXT "The .cub extension is needed\n"
# define ERR_FD "The file does not exist\n"
# define ERR_PERM "Do not have permission to read this file\n"
# define ERR_OPEN "Error opening file\n"
# define ERR_EMPTY "Empty file\n"

typedef struct s_data
{
	int		fd;
	char	**map;
}	t_data;

/* UTILS.C */
void	init_data(t_data *data);
int		ft_error(char *error, t_data *data);

/* ARG.C */
void	check_arg(int argc, char **argv);
void	check_file(char *argv, t_data *data);
void	read_write_file(t_data *data);
void	parser(int argc, char **argv, t_data *data);

#endif