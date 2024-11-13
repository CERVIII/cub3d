/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/13 15:49:02 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// touch function 
int	touch(double px, double py, t_game *game)
{
	int	x;
	int	y;

	x = px / WALL_SIZE;
	y = py / WALL_SIZE;
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

void	draw_line(t_game *game, double start_x)
{
	int	ray_x;
	int	ray_y;

	ray_x = game->data.player_xpx + 5;
	ray_y = game->data.player_ypx;
	while (!touch(ray_x, ray_y, game))
	{
		put_pixel(ray_x, ray_y, 0xFF0000, &game->image);
		ray_x += cos(start_x);
		ray_y += sin(start_x);
	}
}

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
	double	start_x;
	double	fraction;

	fraction = PI / 3 / (WALL_SIZE * game->width);
	start_x = (game->player.dir_x) - PI / 6;
//	printf("FRACTION: %f, START_X: %f\n", fraction, start_x);
	draw_line(game, start_x);
	game->color = 0x00FF00;
	start_x += fraction;
	print_cube(x, y, 10, game);
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
