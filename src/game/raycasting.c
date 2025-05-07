/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:27 by pcervill          #+#    #+#             */
/*   Updated: 2025/05/07 12:24:33 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	touch(double px, double py, t_game *game)
{
	int	x;
	int	y;

	x = (int)px / WALL_SIZE;
	y = (int)py / WALL_SIZE;
	if (game->map[y][x] == '1' || game->map[y][x] == ' ')
		return (1);
	return (0);
}

void	draw_floor_sky(t_game *game, int x)
{
	int	line_height;
	int	start;
	int	end;

	game->color = rgb_to_hex(game->data.c[0], game->data.c[1], game->data.c[2]);
	line_height = (int)(SCREEN_Y / game->ray.dist);
	start = -1;
	end = -line_height / 2 + SCREEN_Y / 2;
	if (start < 0)
		start = -1;
	if (end >= SCREEN_Y)
		end = SCREEN_Y - 1;
	while (start++ < end)
		put_pixel(x, start, game->color, &game->image);
	game->color = rgb_to_hex(game->data.f[0], game->data.f[1], game->data.f[2]);
	start = (line_height / 2 + SCREEN_Y / 2) - 1;
	end = SCREEN_Y;
	if (start < 0)
		start = -1;
	while (start++ < end)
		put_pixel(x, start, game->color, &game->image);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(SCREEN_Y / ray->dist);
	draw_start = (-line_height / 2 + SCREEN_Y / 2) - 1;
	draw_end = line_height / 2 + SCREEN_Y / 2;
	if (draw_start < 0)
		draw_start = -1;
	if (draw_end >= SCREEN_Y)
		draw_end = SCREEN_Y - 1;
	while (draw_start++ < draw_end)
		paint_texture(x, draw_start, ray, game);
}

void	dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (MINIMAP)
			put_pixel(ray->map_x, ray->map_y, 0xFF0000, &game->image);
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->hit = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->hit = 1;
		}
		if (touch(ray->map_x, ray->map_y, game))
			break ;
	}
}

void	raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < SCREEN_X)
	{
		init_ray(game, &game->ray, i);
		dda(game, &game->ray);
		calculate_distance(&game->ray);
		if (!MINIMAP)
		{
			draw_wall(game, &game->ray, i);
			draw_floor_sky(game, i);
		}
		i++;
	}
}
