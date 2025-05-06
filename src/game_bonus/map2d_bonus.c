/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2025/05/06 21:31:34 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

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
		put_pixel((x + i), y , game->color, &game->image_minimap);
		put_pixel(x, (y + i), game->color, &game->image_minimap);
		put_pixel((x + size), (y + i), game->color, &game->image_minimap);
		put_pixel((x + i), (y + size), game->color, &game->image_minimap);
		i++;
	}
}

void	print_player(int x, int y, t_game *game)
{
	int	player;

	player = WALL_SIZE / 2;
	game->color = 0x00FF00;
	print_cube((x - (player / 2)), (y - (player / 2)), player, game);
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
