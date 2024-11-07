/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:18:27 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:32 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 1

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
# define W_L 119
# define A_L 97
# define S_L 115
# define D_L 100
# define LEFT_L 65361
# define RIGHT_L 65363
# define ESC_L 65307

# define DESTROY 17

# define PI 3.14159265359

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			color;
	t_player	player;

	char		**map;
}	t_game;

/* RAYCASTING.C */
float	distance(float x, float y);
float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game);
bool	touch(float px, float py, t_game *game);
char	**get_map(void);
void	init_game(t_game *game);
void	draw_line(t_player *player, t_game *game, float start_x, int i);
int		draw_loop(t_game *game);
int		end_program(void *l);

/* PLAYER.C */
void	init_player(t_player *player);
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);

/* DRAW_PX.C */
void	clear_image(t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, t_game *game);
void	draw_map(t_game *game);

#endif
