/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:48:15 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/04/24 19:49:31 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	load_wall_textures(t_game *game)
{
	game->textures[0] = load_xpm_texture(game->data.no, game);
	game->textures[1] = load_xpm_texture(game->data.so, game);
	game->textures[2] = load_xpm_texture(game->data.we, game);
	game->textures[3] = load_xpm_texture(game->data.ea, game);
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

	pos_camera = 2 * i / (double)SCREEN_X - 1;
	ray->player_angle = atan2(game->player.dir_y, game->player.dir_x);
	ray->ray_angle = ray->player_angle + pos_camera * (PI / 6);
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
		ray->dist = (ray->map_x - ray->ray_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
		ray->dist = ray->side_dist_x - ray->delta_x;
	}
	else
	{
		ray->dist = (ray->map_y - ray->ray_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
		ray->dist = ray->side_dist_y - ray->delta_y;
	}
}

void	get_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (c == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (c == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (c == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	game->player.plane_x = game->player.dir_y * 0.66;
	game->player.plane_y = game->player.dir_x * 0.66;
}
