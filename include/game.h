/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:42 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/22 15:39:03 by pcervill         ###   ########.fr       */
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
	t_mlx		mlx;
	t_player	player;
	t_img		image;
	t_data		data;
}	t_game;

/* MAP2D.C */
void	print_cube(int x, int y, t_game *game, int color);
void	print_player(int x, int y, t_game *game);
void	print_map2d(t_game *game);

/* GAME.C */
void	init_mlx(t_game *game, t_mlx *mlx);
void	init_game(t_game *game);
void	ft_game(t_game *game);

#endif
