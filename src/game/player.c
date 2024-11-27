/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/27 14:18:58 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	lateral_movs(t_game *game)
{
	char	**map;
	double	speed;

	speed = game->player.move_speed;
	map = game->map;
	if (game->keys.a)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y - \
			game->player.dir_x * (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_x * speed;
			game->data.player_ypx -= game->player.dir_x * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)]
			[(int)(game->data.player_x + game->player.dir_y * \
			(speed + 0.125))]))
		{
			game->data.player_x += game->player.dir_y * speed;
			game->data.player_xpx += game->player.dir_y * (speed * WALL_SIZE);
		}
	}
	if (game->keys.d)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y + \
			game->player.dir_x * (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_x * speed;
			game->data.player_ypx += game->player.dir_x * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x - game->player.dir_y * \
			(speed + 0.125))]))
		{
			game->data.player_x -= game->player.dir_y * speed;
			game->data.player_xpx -= game->player.dir_y * (speed * WALL_SIZE);
		}
	}
}

static void	horizontal_movs(t_game *game)
{
	char	**map;
	double	speed;

	speed = game->player.move_speed;
	map = game->map;
	if (game->keys.w)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y + \
			game->player.dir_y * (speed + 0.125))] \
			[(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_y * speed;
			game->data.player_ypx += game->player.dir_y * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x + game->player.dir_x * \
			(speed + 0.125))]))
		{
			game->data.player_x += game->player.dir_x * speed;
			game->data.player_xpx += game->player.dir_x * (speed * WALL_SIZE);
		}
	}
	if (game->keys.s)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y - \
			game->player.dir_y * (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_y * speed;
			game->data.player_ypx -= game->player.dir_y * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x - game->player.dir_x * \
			(speed + 0.125))]))
		{
			game->data.player_x -= game->player.dir_x * speed;
			game->data.player_xpx -= game->player.dir_x * (speed * WALL_SIZE);
		}
	}
}

static void	rotate(t_player *player, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(rotSpeed) - \
		player->dir_y * sin(rotSpeed);
	player->dir_y = old_dir_x * sin(rotSpeed) + \
		player->dir_y * cos(rotSpeed);
	player->plane_x = player->plane_x * cos(rotSpeed) - \
		player->plane_y * sin(rotSpeed);
	player->plane_y = old_plane_x * sin(rotSpeed) + \
		player->plane_y * cos(rotSpeed);
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
