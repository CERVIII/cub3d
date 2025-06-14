/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/03 12:02:47 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

static void	try_move(double dx, double dy, t_game *g)
{
	double	new_x;
	double	new_y;

	new_x = g->data.player_x + dx;
	new_y = g->data.player_y + dy;
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != ' '
		&& g->map[(int)new_y][(int)new_x] != 'C'
		&& g->map[(int)new_y][(int)g->data.player_x] != '1'
		&& g->map[(int)g->data.player_y][(int)new_x] != '1')
	{
		g->data.player_x = new_x;
		g->data.player_xpx = new_x;
		g->data.player_y = new_y;
		g->data.player_ypx = new_y;
	}
}

static void	move_player(t_game *g)
{
	double	dx;
	double	dy;
	double	s;

	s = g->player.move_speed;
	dx = 0.0;
	dy = 0.0;
	if (g->keys.w)
		dx += g->player.dir_x * s;
	if (g->keys.w)
		dy += g->player.dir_y * s;
	if (g->keys.s)
		dx -= g->player.dir_x * s;
	if (g->keys.s)
		dy -= g->player.dir_y * s;
	if (g->keys.d)
		dx -= g->player.dir_y * s;
	if (g->keys.d)
		dy += g->player.dir_x * s;
	if (g->keys.a)
		dx += g->player.dir_y * s;
	if (g->keys.a)
		dy -= g->player.dir_x * s;
	try_move(dx, dy, g);
}

void	rotate(t_player *player, double rotSpeed)
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
	if (game->keys.e)
		swich_door_state(game);
	move_player(game);
	rotation_player(game);
	return (0);
}
