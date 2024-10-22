/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:50 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/22 15:50:27 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'w')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = game->player.dir_x * 0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
}

void	init_game(t_game *game)
{
	int	x;
	int	y;

	game->map = game->data.map;
	game->heigh = game->data.heigh - 1;
	game->width = game->data.width - 1;
	game->player.move_speed = 0.01;
	game->player.rot_speed = 0.05;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
				get_direction(game, game->map[x][y]);
			}
			x++;
		}
		y++;
	}
}

void	init_mlx(t_game *game, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
//	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_X, SCREEN_Y, NAME);
	mlx->mlx_win = mlx_new_window(mlx->mlx, (game->width * 30), (game->heigh * 30), NAME);
	print_map2d(game);
	mlx_loop(mlx->mlx);
}

void	ft_game(t_game *game)
{
	init_game(game);
	init_mlx(game, &game->mlx);
}
