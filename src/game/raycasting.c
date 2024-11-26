/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:26:27 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/26 13:30:32 by pcervill         ###   ########.fr       */
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

void	init_nextraystep(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->ray_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->ray_x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->ray_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->ray_y) * ray->delta_y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int i)
{
	double	pos_camera;
	double	player_angle;

	pos_camera = 2 * i / (double)SCREEN_X - 1;
	player_angle = atan2(game->player.dir_y, game->player.dir_x);
	ray->ray_angle = player_angle + pos_camera * (PI / 6);
	ray->ray_x = game->data.player_xpx;
	ray->ray_y = game->data.player_ypx;
	ray->map_x = ray->ray_x;
	ray->map_y = ray->ray_y;
	ray->ray_dir_x = cos(ray->ray_angle);
	ray->ray_dir_y = sin(ray->ray_angle);
	ray->delta_x = fabs(1 / ray->ray_dir_x);
	ray->delta_y = fabs(1 / ray->ray_dir_y);
	init_nextraystep(ray);
	return ;
}

void	calculate_distance(t_ray *ray)
{
	if (ray->hit == 0)
	{
		ray->dist = (ray->map_x - ray->ray_x + (1 - ray->step_x) \
			/ 2) / ray->ray_dir_x;
		ray->dist = ray->side_dist_x - ray->delta_x;
	}
	else
	{
		ray->dist = (ray->map_y - ray->ray_y + (1 - ray->step_y) \
			/ 2) / ray->ray_dir_y;
		ray->dist = ray->side_dist_y - ray->delta_y;
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;

	line_height = (int)(SCREEN_Y / ray->dist);
	draw_start = -line_height / 2 + SCREEN_Y / 2;
	draw_end = line_height / 2 + SCREEN_Y / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= SCREEN_Y)
		draw_end = SCREEN_Y - 1;
	y = draw_start;
	while (y < draw_end)
	{
		if (ray->hit == 0)
		{
			if (ray->ray_dir_x > 0)		// EAST
				put_pixel(x, y, 0xFF0000, &game->image);
			else
				put_pixel(x, y, 0x555500, &game->image);
		}
		else
		{
			if (ray->ray_dir_y > 0)		// SOUTH
				put_pixel(x, y, 0x00FF00, &game->image);
			else
				put_pixel(x, y, 0x005555, &game->image);
		}
		y++;
	}
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
			draw_wall(game, &game->ray, i);
		i++;
	}
}

/* double	distance(double x, double y)
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
} */

/* void	draw_line(t_game *game, t_ray *ray, int i)
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
			put_pixel((int)ray->ray_x, (int)ray->ray_y, 0xFF0000, &game->image);
		ray->ray_x += step_x;
		ray->ray_y += step_y;
	}
	if (!MINIMAP)
	{
		
	}
}

void	print_rays(t_game *game)
{
	int		i;
	double	start_angle;
	double	angle_step;
	double	player_angle;

	player_angle = atan2(game->player.dir_y, game->player.dir_x);
	printf("ANLGE: %f\n", player_angle);
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
} */
