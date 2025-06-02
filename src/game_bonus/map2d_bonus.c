/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/02 21:36:53 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	put_minimap_pixel(int x, int y, int color, t_img *image)
{
	int	index;

	if (x >= MINIMAP_X || y >= MINIMAP_Y || x < 0 || y < 0)
		return ;
	index = y * image->len + x * image->bpp / 8;
	image->data[index] = color & 0xFF;
	image->data[index + 1] = (color >> 8) & 0xFF;
	image->data[index + 2] = (color >> 16) & 0xFF;
}

void	put_pixel(int x, int y, int color, t_img *image)
{
	int	index;

	if (x >= SCREEN_X || y >= SCREEN_Y || x < 0 || y < 0)
		return ;
	index = y * image->len + x * image->bpp / 8;
	image->data[index] = color & 0xFF;
	image->data[index + 1] = (color >> 8) & 0xFF;
	image->data[index + 2] = (color >> 16) & 0xFF;
	image->data[index + 3] = (color >> 24) & 0xFF;
}

void	print_cube(int x, int y, int size, t_game *game)
{
	int	i;
	int	j;
	int	scaled_size;
	int	sx;
	int	sy;

	scaled_size = size * game->minimap_scale;
	sx = x * game->minimap_scale;
	sy = y * game->minimap_scale;
	j = 0;
	while (j < scaled_size)
	{
		i = 0;
		while (i < scaled_size)
		{
			if (sx + i >= 0 && sx + i < MINIMAP_X
				&& sy + j >= 0 && sy + j < MINIMAP_Y)
				put_minimap_pixel(sx + i, sy + j,
					game->color, &game->image_minimap);
			i++;
		}
		j++;
	}
}

void	print_player(int x, int y, t_game *game)
{
	game->minimap_scale = (double)(MINIMAP_X) / game->width;
	if ((double)(MINIMAP_Y) / game->heigh < game->minimap_scale)
		game->minimap_scale = (double)(MINIMAP_Y) / game->heigh;
	game->color = 0xFF0808;
	print_cube(x, y, 1, game);
}

void	print_map2d(t_game *game)
{
	int		x;
	int		y;

	game->minimap_scale = (double)(MINIMAP_X) / game->width;
	if ((double)(MINIMAP_Y) / game->heigh < game->minimap_scale)
		game->minimap_scale = (double)(MINIMAP_Y) / game->heigh;
	game->color = 0x000000;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				print_cube(x, y, 1, game);
			x++;
		}
		y++;
	}
}
