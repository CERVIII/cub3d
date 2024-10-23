/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:42 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:26 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_opengl/minilibx_opengl_20191021/mlx.h"
# include "../minilibx-linux/mlx.h"

# define WALL_SIZE 64
# define SCREEN_X 800
# define SCREEN_Y 800
# define NAME "CUB3D"

# define KEY_PRESS 2
# define KEY_OFF 3

/* MAC */
# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53

/* LINUX */
# define A_L 97
# define D_L 100
# define S_L 115
# define W_L 119
# define L 65361
# define U 65362
# define R 65363
# define DW 65364
# define ESC_L 65307
# define DESTROY 17

typedef struct s_keys
{
	int	a;
	int	w;
	int	d;
	int	s;
	int	right;
	int	left;
	int	esc;
}	t_keys;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			**tex_buf;
	int			**texture;
	int			fd;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*data;
	char	*path;
	int		width;
	int		height;
	int		endian;
	int		len;
	int		bpp;
}	t_img;

typedef struct s_game
{
	int			heigh;
	int			width;
	char		**map;
	char		**texture;
	t_keys		keys;
	t_mlx		mlx;
	t_player	player;
	t_img		image;
	t_data		data;
}	t_game;

/* EVENTS.C */
int				end_program(void *l);
//static void		horizontal_movs(t_game *game);
//static void	lateral_movs(t_game *game);
//static void	rotation_movs(t_game *game);
int				handle_movements(t_game *game);

/* MAP2D.C */
void			print_cube(int x, int y, t_game *game, int color);
void			print_player(int x, int y, t_game *game);
void			print_map2d(t_game *game);

/* GAME.C */
void			init_mlx(t_game *game, t_mlx *mlx);
void			init_game(t_game *game);
void			ft_game(t_game *game);

#endif
