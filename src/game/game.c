/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:50 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/23 15:44:06 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'w')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = game->player.dir_x * 0.66;
	game->player.plane_y = game->player.dir_y * 0.66;
}

void	init_key(t_keys *key)
{
	key->a = 0;
	key->w = 0;
	key->s = 0;
	key->d = 0;
	key->left = 0;
	key->right = 0;
	key->esc = 0;
}

void	init_game(t_game *game)
{
	int	x;
	int	y;

	game->map = game->data.map;
	game->heigh = game->data.heigh - 1;
	game->width = game->data.width - 1;
	game->player.move_speed = 0.01;
	game->player.rot_speed = 0.05;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
				get_direction(game, game->map[x][y]);
			}
			x++;
		}
		y++;
	}
	init_key(&game->keys);
}

int	pulse_key(int key, t_game *game)
{
	if (key == ESC || key == ESC_L)
		end_program(game);
	if (key == A || key == A_L)
		game->keys.a = 1;
	if (key == W || key == W_L)
		game->keys.w = 1;
	if (key == S || key == S_L)
		game->keys.s = 1;
	if (key == D || key == D_L)
		game->keys.d = 1;
	if (key == LEFT || key == L)
		game->keys.left = 1;
	if (key == RIGHT || key == R)
		game->keys.right = 1;
	return (0);
}

int	release_key(int key, t_game *game)
{
	if (key == A || key == A_L)
		game->keys.a = 0;
	if (key == W || key == W_L)
		game->keys.w = 0;
	if (key == S || key == S_L)
		game->keys.s = 0;
	if (key == D || key == D_L)
		game->keys.d = 0;
	if (key == LEFT || key == L)
		game->keys.left = 0;
	if (key == RIGHT || key == R)
		game->keys.right = 0;
	return (0);
}

int	handle_loop(t_game *game)
{
	print_map2d(game);
	handle_movements(game);
	return (0);
}

void	init_mlx(t_game *game, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
//	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_X, SCREEN_Y, NAME);
	mlx->mlx_win = mlx_new_window(mlx->mlx, (game->width * 30),
			(game->heigh * 30), NAME);
	game->image.img = mlx_new_image(game->mlx.mlx, SCREEN_X, SCREEN_Y);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, \
				&game->image.bpp, &game->image.len, &game->image.endian);
	mlx_loop_hook(game->mlx.mlx, &handle_loop, game);
	mlx_hook(game->mlx.mlx_win, DESTROY, 0, &end_program, game);
	mlx_hook(game->mlx.mlx_win, KEY_PRESS, (1L << 0), &pulse_key, game);
	mlx_hook(game->mlx.mlx_win, KEY_OFF, (1L << 1), &release_key, game);
	mlx_loop(mlx->mlx);
}

void	ft_game(t_game *game)
{
	init_game(game);
	init_mlx(game, &game->mlx);
}
