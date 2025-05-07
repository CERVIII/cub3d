/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2025/05/07 15:00:11 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	try_move(double dx, double dy, t_game *g)
{
    double	new_x;
    double	new_y;

	new_x = g->data.player_x + dx;
	new_y = g->data.player_y + dy;
	if ((int)g->data.player_x == (int)new_x
		&& (int)g->data.player_y == (int)new_y)
	{
		g->data.player_x = new_x;
		g->data.player_xpx = new_x;
		g->data.player_y = new_y;
		g->data.player_ypx = new_y;
	}
	else
	{
		if (g->map[(int)new_y][(int)new_x] != '1')
		{
			g->data.player_x = new_x;
			g->data.player_xpx = new_x;
			g->data.player_y = new_y;
			g->data.player_ypx = new_y;
		}
	}
}

static void	move_player(t_game *g)
{
    double dx = 0.0, dy = 0.0;
    double s  = g->player.move_speed;

    if (g->keys.w)
    {
        dx += g->player.dir_x * s;
        dy += g->player.dir_y * s;
    }
    if (g->keys.s)
    {
        dx -= g->player.dir_x * s;
        dy -= g->player.dir_y * s;
    }
    if (g->keys.d)
    {
        dx -= g->player.dir_y * s;
        dy += g->player.dir_x * s;
	}
    if (g->keys.a)
    {
        dx += g->player.dir_y * s;
        dy -= g->player.dir_x * s;
    }
	try_move(dx, dy, g);
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
	move_player(game);
	rotation_player(game);
	return (0);
}
