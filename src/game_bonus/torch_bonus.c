/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:58:58 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/06/02 17:06:26 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	load_torch_textures(t_game *game)
{
	game->torch.frames[0] = load_xpm_texture("./textures/greenlight.xpm", game);
	/*game->torch.frames[0] = load_xpm_texture("./sprites/torch/f0.xpm", game);*/
	/*game->torch.frames[1] = load_xpm_texture("./sprites/torch/f1.xpm", game);*/
	/*game->torch.frames[2] = load_xpm_texture("./sprites/torch/f2.xpm", game);*/
	/*game->torch.frames[3] = load_xpm_texture("./sprites/torch/f3.xpm", game);*/
	/*game->torch.frames[4] = load_xpm_texture("./sprites/torch/f4.xpm", game);*/
	/*game->torch.frames[5] = load_xpm_texture("./sprites/torch/f5.xpm", game);*/
	/*game->torch.frames[6] = load_xpm_texture("./sprites/torch/f6.xpm", game);*/
	/*game->torch.frames[7] = load_xpm_texture("./sprites/torch/f7.xpm", game);*/
	/*game->torch.frames[8] = load_xpm_texture("./sprites/torch/f8.xpm", game);*/
}

int	check_torch_file(char *path)
{
	int	temp_fd;

	if (access(path, F_OK) == -1)
		ft_error(ERR_FD, NULL, path);
	if (access(path, R_OK) == -1)
		ft_error(ERR_READ, NULL, path);
	temp_fd = open(path, O_RDONLY);
	if (temp_fd == -1)
		ft_error(ERR_OPEN, NULL, path);
	return (close(temp_fd), 0);
}

int	check_torch_files(void)
{
	if (check_torch_file("./textures/greenlight.xpm") != 0)
		return (1);
	/*if (check_torch_file("./sprites/torch/f0.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f1.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f2.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f3.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f4.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f5.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f6.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f7.xpm") != 0)*/
	/*	return (1);*/
	/*if (check_torch_file("./sprites/torch/f8.xpm") != 0)*/
	/*	return (1);*/
	return (0);
}

void	init_torch(t_game *game)
{
	if (check_torch_files() != 0 || SCREEN_X < 64 || SCREEN_Y < 64)
	{
		game->torch_on = 0;
		return ;
	}
	load_torch_textures(game);
	game->torch.current = 0;
	game->torch.frame_count = 9;
	game->torch.animation_count = 0;
	game->torch.animation_speed = 20;
	game->torch.width = game->torch.frames[0].w;
	game->torch.height = game->torch.frames[0].h;
	printf("Width: %d\n", game->torch.width);
	printf("Height: %d\n", game->torch.height);
	game->torch.scale = (SCREEN_Y * 0.3) / game->torch.height;
	game->torch.img_h = (int)(game->torch.height * game->torch.scale);
	game->torch.img_w = (int)(game->torch.width * game->torch.scale);
	printf("NEW WIDTH: %d\n NEW HEIGHT: %d\n", game->torch.img_w, game->torch.img_h);
	game->torch_on = 1;
}

void	torch_loop(t_game *game)
{
	if (game->torch_on == 0)
		return ;
	game->torch.animation_count++;
	if (game->torch.animation_count >= game->torch.animation_speed)
	{
		game->torch.animation_count = 0;
		if (game->torch.current < 0)
			game->torch.current += 1;
		else
			game->torch.current = 0;
	}
	paint_torch_frame(game);
}

void	paint_torch_frame(t_game *game)
{
	int		x_dst;
	int		y_dst;
	int		x_src;
	int		y_src;
	int		current;
	int		color;

	current = game->torch.current;
	y_dst = 0;
	while (y_dst < game->torch.img_h)
	{
		x_dst = 0;
		y_src = (int)(y_dst / game->torch.scale);
		if (y_src >= game->torch.height)
			y_src = game->torch.height - 1;
		while (x_dst < game->torch.img_w)
		{
			x_src = (int)(x_dst / game->torch.scale);
			if (x_src >= game->torch.width)
				x_src = game->torch.width - 1;
			color = *(int *)(game->torch.frames[current].data + (y_src
				* game->torch.frames[current].line_len)
				+ x_src * (game->torch.frames[current].bpp / 8));
			if (color != 0)
				put_pixel(x_dst
					+ (SCREEN_X - game->torch.img_w - 10),
					y_dst + (SCREEN_Y - game->torch.img_h),
					color, &game->image);
			x_dst++;
		}
		y_dst++;
	}
}
