/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/24 15:27:50 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_cube(int x, int y, t_game *game, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < (y + WALL_SIZE - 1))
	{
		j = x;
		mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j++, i, 0xFF0000);
		while (j < (x + WALL_SIZE - 1))
		{
			if (i == y)
				mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j, i, 0xFF0000);
			else
				mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j, i, color);
			mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j, i + 1, 0xFF0000);
			j++;
		}
		mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j, i, 0xFF0000);
		++i;
	}
}

void	print_player(int x, int y, t_game *game)
{
	int	i;
	int	j;

	i = y - WALL_SIZE / 4;
	while (i < (y + WALL_SIZE / 4))
	{
		j = x - (WALL_SIZE / 4);
		while (j < (x + WALL_SIZE / 4))
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j, i, 0x00FF00);
			j++;
		}
		i++;
	}
}

void	print_map2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				print_cube(x * WALL_SIZE, y * WALL_SIZE, game, 0x0000FF);
			else if (game->map[y][x] == '0')
				print_cube(x * WALL_SIZE, y * WALL_SIZE, game, 0x000000);
			else if (ft_strchr("NSEW", game->map[y][x]))
				print_cube(x * WALL_SIZE, y * WALL_SIZE, game, 0x000000);
			x++;
		}
		y++;
	}
	print_player(game->data.player_xpx, game->data.player_ypx, game);
}
