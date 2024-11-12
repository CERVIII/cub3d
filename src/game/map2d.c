/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:56:11 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/12 15:32:09 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
/* void	draw_line(t_img *image, int x1, int y1, int x2, int y2)
{
	int	step;
	int	delta_x;
	int	delta_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	step = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= step;
	delta_y /= step;
	while (step)
	{
		put_pixel(x1, y1, 0xFF0000, image);
		x1 += delta_x;
		y1 += delta_y;
		step--;
	}
} */

void	draw_line(t_img *image, t_data *data, int x, int y)
{
	int	step;
	int	i;
	int	delta_x;
	int	delta_y;

	delta_x = x - data->player_xpx;
	delta_y = y - data->player_ypx;
	if (abs(delta_x) >= abs(delta_y))
		step = abs(delta_x);
	else
		step = abs(delta_y);
	delta_x /= step;
	delta_y /= step;
	x = data->player_xpx + 5;
	y = data->player_ypx;
	i = 0;
	while (i < step)
	{
		put_pixel(x, y, 0xFF0000, image);
		x += delta_x;
		y += delta_y;
		i++;
	}
}

// touch function 
int	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / WALL_SIZE;
	y = py / WALL_SIZE;
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

/* void	draw_line(t_data *data, t_game *game, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
//	float	dist;
//	float	height;
//	int		start_y;
//	int		end;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = data->player_x;
	ray_y = data->player_y;
	while (!touch(ray_x, ray_y, game))
	{
		put_pixel(ray_x, ray_y, 0xFF0000, &game->image);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
 	if (!DEBUG)
	{
		dist = fixed_dist(data->player_x, data->player_y, ray_x, ray_y, game);
		height = (WALL_SIZE / dist) * (SCREEN_X / 2);
		start_y = (SCREEN_Y - height) / 2;
		end = start_y + height;
		while (start_y < end)
		{
			put_pixel(i, start_y, 255, game);
			start_y++;
		}
	}
} */

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
//	int		i;
//	float	fraction;
//	float	start_x;

	game->color = 0x00FF00;
/* 	print_cube(x * WALL_SIZE + (WALL_SIZE / 2), \
		y * WALL_SIZE + (WALL_SIZE / 2), 10, game); */
	print_cube(x, y, 10, game);
//	fraction = 3.1416 / 3 / SCREEN_X;
//	start_x = game->player.rot_speed - 3.1416 / 6;
//	draw_line(&game->data, game, start_x);
/* 	i = 0;
	while(i < SCREEN_X)
	{
		draw_line(&game->data, game, start_x);
		start_x += fraction;
		i++;
	} */
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
