/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:47:07 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/03 14:06:52 by pcervill         ###   ########.fr       */
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

/* MAC */
# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define UP 126
# define ESC 53

/* LINUX */
# define A_L 97
# define W_L 119
# define D_L 100
# define S_L 115
# define L 65361
# define U 65362
# define R 65363
# define DW 65364
# define ESC_L 65307

/* ERROR */
# define ERR_ARG "Not valid arguments"
# define ERR_NAME "The name is very short"
# define ERR_EXT "The .cub extension is needed"
# define ERR_FD "The file does not exist "
# define ERR_READ "Do not have permission to read this file "
# define ERR_OPEN "Error opening file "
# define ERR_EMPTY "Empty file"
# define ERR_TEXT "Invalid value for textures and colors"
# define ERR_COL "Floor or ceiling value's are not numbers"

typedef struct s_data
{
	int		fd;
	char	**file;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}	t_data;


/* UTILS.C */
void	init_data(t_data *data);
void	free_all(t_data *data);
int		ft_error(char *error, t_data *data, char *file);

/* ARG.C */
void	check_arg(int argc, char **argv);
void	check_file(char *argv, t_data *data);
void	read_write_file(t_data *data);
void	check_texture(t_data *data);
char	*save_texture(char *texture, t_data *data);
int		*save_color(char *texture, t_data *data);
void	parser(int argc, char **argv, t_data *data);

#endif