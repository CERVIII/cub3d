/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/13 15:44:52 by pcervill         ###   ########.fr       */
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
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y + \
			game->player.dir_x * (speed))][(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_x * speed;
			game->data.player_ypx += game->player.dir_x * 1;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x + game->player.dir_y * \
				(speed))]))
		{
			game->data.player_x += game->player.dir_y * speed;
			game->data.player_xpx += game->player.dir_y * 1;
		}
	}
	if (game->keys.d)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y - \
			game->player.dir_x * (speed * 10))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_x * speed;
			game->data.player_ypx -= game->player.dir_x * 1;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
		[(int)(game->data.player_x - game->player.dir_y * (speed * 10))]))
		{
			game->data.player_x -= game->player.dir_y * speed;
			game->data.player_xpx -= game->player.dir_y * 1;
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
			game->player.dir_y * (speed))][(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_y * speed;
			game->data.player_ypx += game->player.dir_y * 1;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x + game->player.dir_x * \
				(speed))]))
		{
			game->data.player_x += game->player.dir_x * speed;
			game->data.player_xpx += game->player.dir_x * 1;
		}
	}
	if (game->keys.s)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y - \
		game->player.dir_y * (speed * 10))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_y * speed;
			game->data.player_ypx -= game->player.dir_y * 1;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
		[(int)(game->data.player_x - game->player.dir_x * (speed * 10))]))
		{
			game->data.player_x -= game->player.dir_x * speed;
			game->data.player_xpx -= game->player.dir_x * 1;
		}
	}
}

static void	rotate(t_player *player, double speed)
{
	double	sin_s;
	double	cos_s;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	sin_s = sin(speed);
	cos_s = cos(speed);
	player->dir_x = player->dir_x * cos_s - player->dir_y * sin_s;
	player->dir_y = old_dir_x * sin_s + player->dir_y * cos_s;
	player->plane_x = player->plane_x * cos_s - player->plane_y * sin_s;
	player->plane_y = old_plane_x * sin_s + player->plane_y * cos_s;
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
