/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:13:26 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/30 15:58:37 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_player *player)
{
	if (keycode == ESC_L || keycode == ESC)
		end_program(player);
	if (keycode == W || keycode == W_L)
		player->key_up = true;
	if (keycode == S || keycode == S_L)
		player->key_down = true;
	if (keycode == A || keycode == A_L)
		player->key_left = true;
	if (keycode == D || keycode == D_L)
		player->key_right = true;
	if (keycode == LEFT || keycode == LEFT_L)
		player->left_rotate = true;
	if (keycode == RIGHT || keycode == RIGHT_L)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	move_direction(t_player *player, t_game *game, float cos_angle, float sin_angle)
{
	float	speed;

	speed = 3;
	if (player->key_up && !touch((player->x + (cos_angle * speed)),
			(player->y + (sin_angle * speed)), game))
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down && !touch((player->x - (cos_angle * speed)),
			(player->y - (sin_angle * speed)), game))
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_left && !touch((player->x + (sin_angle * speed)),
			(player->y - (cos_angle * speed)), game))
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (player->key_right && !touch((player->x - (sin_angle * speed)),
			(player->y + (cos_angle * speed)), game))
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
}

void	move_player(t_player *player, t_game *game)
{
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	move_direction(player, game, cos_angle, sin_angle);
}
