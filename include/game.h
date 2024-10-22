/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:42 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/21 23:20:11 by pcervill         ###   ########.fr       */
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

# define SCREEN_X 800
# define SCREEN_Y 600
# define NAME "CUB3D"

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	double	move_speed;
	double	rot_speed;
	double	plane_x;
	double	plane_y;
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
}	t_game;

/* GAME.C */
void	init_mlx(t_game *game, t_mlx *mlx);
void	init_game(t_game *game, t_data *data);
void	ft_game(t_data *data);

#endif
