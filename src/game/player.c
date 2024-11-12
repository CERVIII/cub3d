/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:16:08 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/12 12:33:17 by pcervill         ###   ########.fr       */
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
	printf("ACTUAL\n");
	printf("pl_y: %f pl_x: %f\n", game->data.player_ypx, game->data.player_xpx);
	printf("pl_y: %f pl_x: %f\n", game->data.player_y, game->data.player_x);
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
	printf("DESPUES\n");
	printf("pl_y: %f pl_x: %f\n", game->data.player_ypx, game->data.player_xpx);
	printf("pl_y: %f pl_x: %f\n", game->data.player_y, game->data.player_x);
}

/* static void	rotation_player(t_game *game)
{
	int	rot_speed;

	rot_speed = 0;
	if (game->keys.left)
		rot_speed -= game->player.rot_speed;
	else if (game->keys.right)
		rot_speed -= game->player.rot_speed;
	else
		return ;
} */

int	handle_movements(t_game *game)
{
	horizontal_movs(game);
	lateral_movs(game);
//	rotation_player(game);
	return (0);
}
