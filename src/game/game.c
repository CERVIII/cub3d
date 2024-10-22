/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:50 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/22 14:26:52 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_cube(int x, int y, t_game *game, int color, int size)
{
	int	i;
	int	j;

	i = y * size;
	while (i < ((y + 1) * size - 1))
	{
		j = x * size;
		mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j++, i, 0xFF0000);
		while (j < ((x + 1) * size) - 1)
		{
			if (i == (y * size))
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

	print_cube(x, y, game, 0x000000, 30);
	i = (y * 30) + 10;
	while (i < (((y + 1) * 30) - 10))
	{
		j = (x * 30) + 10;
		while (j < (((x + 1) * 30) - 10))
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
				print_cube(x, y, game, 0x0000FF, 30);
			else if (game->map[y][x] == '0')
				print_cube(x, y, game, 0x000000, 30);
			else if (ft_strchr("NSEW", game->map[y][x]))
				print_player(x, y, game);
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

void	init_game(t_game *game)
{
	game->map = game->data.map;
	game->heigh = game->data.heigh - 1;
	game->width = game->data.width - 1;
}

void	ft_game(t_game *game)
{
	init_game(game);
	init_mlx(game, &game->mlx);
}
