/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:45:15 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/03 11:23:50 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	end_program(void *l)
{
	(void)l;
	exit(0);
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
	if (key == E || key == E_L)
		game->keys.e = 1;
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
	if (key == E || key == E_L)
		game->keys.e = 0;
	if (key == LEFT || key == L)
		game->keys.left = 0;
	if (key == RIGHT || key == R)
		game->keys.right = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	double	dx;

	(void)y;
	if (x < 10 || x > SCREEN_X - 10 || y < 10 || y > SCREEN_Y - 10)
	{
		if (game->keys.mouse_inside)
			game->keys.mouse_inside = 0;
	}
	else
	{
		if (!game->keys.mouse_inside)
		{
			game->keys.mouse_inside = 1;
			game->keys.last_mouse_pos = x;
		}
	}
	if (game->keys.mouse_inside == 1)
	{
		dx = (x - game->keys.last_mouse_pos) * game->player.mouse_speed;
		rotate(&game->player, dx);
		game->keys.last_mouse_pos = x;
	}
	return (0);
}

void	clear_image(int max_x, int max_y, int minimap, t_img *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (minimap)
				put_minimap_pixel(x, y, 0xFFFFFF, image);
			else
				put_pixel(x, y, 0xFFFFFF, image);
			x++;
		}
		y++;
	}
}
