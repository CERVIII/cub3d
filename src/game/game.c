/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:50 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/22 00:06:24 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_map2d(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		i = (y * 64);
		while (game->map[y][x])
		{
			j = (x * 64);
			if (game->map[y][x] == '1')
			{
				while (i < ((y + 1) * 64))
				{
					while (j < ((x + 1) * 64))
						mlx_pixel_put(game->mlx.mlx, game->mlx.mlx_win, j++, i, 0x0000FF);
					++i;
				}
			}
			x++;
		}
		y++;
	}
}

void	init_mlx(t_game *game, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(game->mlx.mlx, SCREEN_X, SCREEN_Y, NAME);
	mlx_loop(mlx->mlx);
}

void	init_game(t_game *game, t_data *data)
{
	game->map = data->map;
	game->texture = (char **)ft_calloc(sizeof(char *), 5);
	game->texture[0] = data->no;
	game->texture[1] = data->so;
	game->texture[2] = data->we;
	game->texture[3] = data->ea;
}

void	ft_game(t_data *data)
{
	t_game	game;

	init_game(&game, data);
	init_mlx(&game, &game.mlx);
}
