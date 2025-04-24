/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:45 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	lateral_movs(t_game *game)
{
	char	**map;
	double	speed;

	speed = game->player.move_speed;
	map = game->map;
	handle_left_movs(speed, map, game);
	handle_right_movs(speed, map, game);
}

static void	horizontal_movs(t_game *game)
{
	char	**map;
	double	speed;

	speed = game->player.move_speed;
	map = game->map;
	handle_forward_movs(speed, map, game);
	handle_back_movs(speed, map, game);
}

static void	rotate(t_player *player, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(rotSpeed)
		- player->dir_y * sin(rotSpeed);
	player->dir_y = old_dir_x * sin(rotSpeed) + player->dir_y * cos(rotSpeed);
	player->plane_x = player->plane_x * cos(rotSpeed)
		- player->plane_y * sin(rotSpeed);
	player->plane_y = old_plane_x * sin(rotSpeed)
		+ player->plane_y * cos(rotSpeed);
}

static void	rotation_player(t_game *game)
{
	if (game->keys.left)
		rotate(&game->player, -game->player.rot_speed);
	else if (game->keys.right)
		rotate(&game->player, game->player.rot_speed);
	return ;
}

int	handle_movements(t_game *game)
{
	horizontal_movs(game);
	lateral_movs(game);
	rotation_player(game);
	return (0);
}
