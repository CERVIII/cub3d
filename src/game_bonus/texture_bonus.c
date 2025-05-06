/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:18:59 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/04/24 19:48:41 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_tex_x(int tex_w, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->hit == 0)
		wall_x = ray->ray_y + ray->dist * ray->ray_dir_y;
	else
		wall_x = ray->ray_x + ray->dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex_w);
	if ((ray->hit == 0 && ray->ray_dir_x > 0)
		|| (ray->hit == 1 && ray->ray_dir_y < 0))
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

int	get_tex_y(int screen_y, int tex_h, t_ray *ray)
{
	int		tex_y;
	int		draw_start;
	double	tex_pos;
	double	step;

	draw_start = -((int)(SCREEN_Y / ray->dist)) / 2 + SCREEN_Y / 2;
	step = (double)tex_h / (double)((int)(SCREEN_Y / ray->dist));
	tex_pos = (screen_y - draw_start) * step;
	tex_y = ((int)tex_pos) & (tex_h - 1);
	return (tex_y);
}

uint32_t	get_color(int screen_y, int orientation, t_ray *ray, t_game *game)
{
	int	tex_height;
	int	tex_width;
	int	tex_x;
	int	tex_y;

	tex_height = game->textures[orientation].h;
	tex_width = game->textures[orientation].w;
	tex_x = get_tex_x(tex_width, ray);
	tex_y = get_tex_y(screen_y, tex_height, ray);
	return (game->textures[orientation].data[tex_height * tex_y + tex_x]);
}

void	paint_texture(int x, int draw_start, t_ray *ray, t_game *game)
{
	int	orientation;

	orientation = 0;
	if (ray->hit == 0)
	{
		if (ray->ray_dir_x < 0)
			orientation = 2;
		else
			orientation = 3;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			orientation = 0;
		else
			orientation = 1;
	}
	put_pixel(x, draw_start,
		get_color(draw_start, orientation, ray, game), &game->image);
}

t_texture	load_xpm_texture(char *path, t_game *game)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game->mlx.mlx,
			path, &texture.w, &texture.h);
	if (!texture.img)
	{
		texture.img = NULL;
		texture.data = NULL;
	}
	else
		texture.data = (int *)mlx_get_data_addr(texture.img, &texture.bpp,
				&texture.line_len, &texture.endian);
	return (texture);
}
