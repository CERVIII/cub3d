/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:45:15 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/24 15:56:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	end_program(void *l)
{
	(void)l;
	exit(0);
}

static void	horizontal_movs(t_game *game)
{
	char	**map;
	double	speed;

	speed = game->player.move_speed;
	map = game->map;
	printf("ANTES\n");
	printf("player_y: %f player_x: %f\n", game->data.player_ypx, game->data.player_xpx);
	printf("player_y: %f player_x: %f\n", game->data.player_y, game->data.player_x);
	if (game->keys.w)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y + \
			game->player.dir_y * (speed + 0.5))] \
			[(int)(game->data.player_x)]))
		{
			game->data.player_y += game->player.dir_y * speed;
			game->data.player_ypx += game->player.dir_y * speed;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
			[(int)(game->data.player_x + game->player.dir_x * \
				(speed + 0.5))]))
		{
			game->data.player_x += game->player.dir_x * speed;
			game->data.player_xpx += game->player.dir_x * speed;
		}
		printf("DESPUES\n");
		printf("player_y: %f player_x: %f\n", game->data.player_ypx, game->data.player_xpx);
		printf("player_y: %d player_x: %d\n", (int)game->data.player_y, (int)game->data.player_x);
	}
	if (game->keys.s)
	{
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y - \
		game->player.dir_y * (speed + 0.5))][(int)(game->data.player_x)]))
		{
			game->data.player_y -= game->player.dir_y * speed;
			game->data.player_ypx -= game->player.dir_y * speed;
		}
		if (ft_strchr("NSEW0", map[(int)(game->data.player_y)] \
		[(int)(game->data.player_x - game->player.dir_x * (speed + 0.5))]))
		{
			game->data.player_x -= game->player.dir_x * speed;
			game->data.player_xpx -= game->player.dir_x * speed;
		}
	}
}

/* static void	lateral_movs(t_game *game)
{
	
}

static void	rotation_player(t_game *game)
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
//	lateral_movs(game);
//	rotation_player(game);
return (0);
}
