/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/21 11:58:34 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	clear_image(t_img *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_Y)
	{
		x = 0;
		while (x < SCREEN_X)
		{
			put_pixel(x, y, 0, image);
			x++;
		}
		y++;
	}
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
}

void	print_cube(int x, int y, int size, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, game->color, &game->image);
		put_pixel(x, y + i, game->color, &game->image);
		put_pixel(x + size, y + i, game->color, &game->image);
		put_pixel(x + i, y + size, game->color, &game->image);
		i++;
	}
}

void	print_player(int x, int y, t_game *game)
{
	game->color = 0x00FF00;
	print_cube(x - 5, y - 5, 10, game);
}

void	print_map2d(t_game *game)
{
	int	x;
	int	y;

	game->color = 0x00FFFF;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				print_cube(x * WALL_SIZE, y * WALL_SIZE, WALL_SIZE, game);
			x++;
		}
		y++;
	}
}
