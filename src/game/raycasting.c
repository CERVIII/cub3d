/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:27 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/20 16:05:08 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

double	distance(double x, double y)
{
	return (sqrt(x * x + y * y));
}

double	ray_dist(t_ray *ray, t_player *player)
{
	double	delta_x;
	double	delta_y;
	double	angle;
	double	dist;

	delta_x = ray->ray_x - player->pos_x;
	delta_y = ray->ray_y - player->pos_y;
	angle = atan2(delta_y, delta_x) - ray->ray_angle;
	dist = distance(delta_x, delta_y) * cos(angle);
	return (dist);
}

void	draw_line(t_game *game, t_ray *ray, int i)
{
	double	step_x;
	double	step_y;
	double	start_y;
	double	end;

	ray->ray_x = game->data.player_xpx;
	ray->ray_y = game->data.player_ypx;
	step_x = cos(ray->ray_angle);
	step_y = sin(ray->ray_angle);
	while (!touch((int)ray->ray_x, (int)ray->ray_y, game))
	{
		if (MINIMAP)
			put_pixel((int)ray->ray_x, (int)ray->ray_y, 0xFFFF0000, &game->image);
		ray->ray_x += step_x;
		ray->ray_y += step_y;
	}
	if (!MINIMAP)
	{
		ray->dist = ray_dist(ray, &game->player);
		ray->height = (WALL_SIZE / ray->dist) * (SCREEN_X / 2);
		start_y = (SCREEN_Y - ray->height) / 2;
		end = start_y + ray->height;
		while (start_y < end)
			put_pixel(i, start_y++, 255, &game->image);
	}
}

void	print_rays(t_game *game)
{
	int		i;
	double	start_angle;
	double	angle_step;
	double	player_angle;

	player_angle = atan2(game->player.dir_y, game->player.dir_x);
	start_angle = player_angle - (PI / 6);
	angle_step = (PI / 3) / SCREEN_X;
	game->ray.ray_angle = start_angle;
	i = 0;
	while (i < SCREEN_X)
	{
		draw_line(game, &game->ray, i);
		game->ray.ray_angle += angle_step;
		i++;
	}
}
