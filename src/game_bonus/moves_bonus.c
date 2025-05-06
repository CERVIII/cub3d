/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:36:01 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/05/06 20:11:40 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	handle_right_movs(double speed, char **map, t_game *game)
{
	if (game->keys.d)
	{
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y + game->player.dir_x
					* (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_x * speed;
			game->data.player_ypx += game->player.dir_x * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y)][(int)(game->data.player_x
			- game->player.dir_y * (speed + 0.125))]))
		{
			game->data.player_x -= game->player.dir_y * speed;
			game->data.player_xpx -= game->player.dir_y * (speed * WALL_SIZE);
		}
	}
}

void	handle_left_movs(double speed, char **map, t_game *game)
{
	if (game->keys.a)
	{
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y - game->player.dir_x
					* (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_x * speed;
			game->data.player_ypx -= game->player.dir_x * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)]
			[(int)(game->data.player_x + game->player.dir_y
				* (speed + 0.125))]))
		{
			game->data.player_x += game->player.dir_y * speed;
			game->data.player_xpx += game->player.dir_y * (speed * WALL_SIZE);
		}
	}
}

void	handle_forward_movs(double speed, char **map, t_game *game)
{
	if (game->keys.w)
	{
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y + game->player.dir_y
					* (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_y * speed;
			game->data.player_ypx += game->player.dir_y * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y)][(int)(game->data.player_x
			+ game->player.dir_x * (speed + 0.125))]))
		{
			game->data.player_x += game->player.dir_x * speed;
			game->data.player_xpx += game->player.dir_x * (speed * WALL_SIZE);
		}
	}
}

void	handle_back_movs(double speed, char **map, t_game *game)
{
	if (game->keys.s)
	{
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y - game->player.dir_y
					* (speed + 0.125))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_y * speed;
			game->data.player_ypx -= game->player.dir_y * (speed * WALL_SIZE);
		}
		if (ft_strchr("NSEW0",
				map[(int)(game->data.player_y)][(int)(game->data.player_x
			- game->player.dir_x * (speed + 0.125))]))
		{
			game->data.player_x -= game->player.dir_x * speed;
			game->data.player_xpx -= game->player.dir_x * (speed * WALL_SIZE);
		}
	}
}
