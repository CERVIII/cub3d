/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:42 by pcervill          #+#    #+#             */
/*   Updated: 2025/05/07 10:41:40 by mpenas-z         ###   ########.fr       */
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

# define NAME "CUB3D"
# define WALL_SIZE 20
# define SCREEN_X 800
# define SCREEN_Y 800
# define PI 3.14159265359

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

typedef struct s_ray
{
	double	player_angle;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dist;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_x;
	int		map_y;
	double	step_x;
	double	step_y;
	double	height;
	int		hit;
}	t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			**tex_buf;
	int			**texture;
	int			h;
	int			w;
	int			fd;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*data;
	char	*path;
	int		width;
	int		height;
	int		endian;
	int		len;
	int		bpp;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		endian;
	int		bpp;
	int		line_len;
	int		w;
	int		h;
}	t_texture;

typedef struct s_game
{
	int			heigh;
	int			width;
	int			color;
	char		**map;
	char		**texture;
	t_texture	textures[4];
	t_keys		keys;
	t_player	player;
	t_ray		ray;
	t_mlx		mlx;
	t_img		image;
	t_data		data;
}	t_game;

/* EVENTS.C */
int			end_program(void *l);
int			pulse_key(int key, t_game *game);
int			release_key(int key, t_game *game);

/* TEXTURE.C */
int			get_tex_x(int tex_w, t_ray *ray);
int			get_tex_y(int screen_y, int tex_h, t_ray *ray);
uint32_t	get_color(int screen_y, int orientation, t_ray *ray, t_game *game);
void		paint_texture(int x, int draw_start, t_ray *ray, t_game *game);
t_texture	load_xpm_texture(char *path, t_game *game);

/* PLAYER.C */
int			handle_movements(t_game *game);

/* MOVES.C */
void		handle_right_movs(double speed, char **map, t_game *game);
void		handle_left_movs(double speed, char **map, t_game *game);
void		handle_forward_movs(double speed, char **map, t_game *game);
void		handle_back_movs(double speed, char **map, t_game *game);

/* MAP2D.C */
int			touch(double px, double py, t_game *game);
void		clear_image(t_img *image);
void		put_pixel(int x, int y, int color, t_img *image);
void		print_cube(int x, int y, int size, t_game *game);
void		print_player(int x, int y, t_game *game);
void		print_map2d(t_game *game);

/* RAYCASTING.C */
void		draw_wall(t_game *game, t_ray *ray, int x);
void		dda(t_game *game, t_ray *ray);
void		raycasting(t_game *game);

double		distance(double x, double y);
double		ray_dist(t_ray *ray, t_player *player);
void		draw_line(t_game *game, t_ray *ray, int i);
void		print_rays(t_game *game);

/* EXTRA.C */
void		get_direction(t_game *game, char c);
void		load_wall_textures(t_game *game);
void		init_nextraystep(t_ray *ray);
void		init_ray(t_game *game, t_ray *ray, int i);
void		calculate_distance(t_ray *ray);

/* GAME.C */
void		init_mlx(t_mlx *mlx, t_img *img);
void		init_game(t_game *game);
void		ft_game(t_game *game);

#endif
