/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:58:58 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/06/02 00:37:43 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	load_torch_textures(t_game *game)
{
	game->torch.frames[0] = load_xpm_texture("./sprites/torch/f0.xpm", game);
	game->torch.frames[1] = load_xpm_texture("./sprites/torch/f1.xpm", game);
	game->torch.frames[2] = load_xpm_texture("./sprites/torch/f2.xpm", game);
	game->torch.frames[3] = load_xpm_texture("./sprites/torch/f3.xpm", game);
	game->torch.frames[4] = load_xpm_texture("./sprites/torch/f4.xpm", game);
	game->torch.frames[5] = load_xpm_texture("./sprites/torch/f5.xpm", game);
	game->torch.frames[6] = load_xpm_texture("./sprites/torch/f6.xpm", game);
	game->torch.frames[7] = load_xpm_texture("./sprites/torch/f7.xpm", game);
	game->torch.frames[8] = load_xpm_texture("./sprites/torch/f8.xpm", game);
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
	if (check_torch_file("./sprites/torch/f0.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f1.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f2.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f3.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f4.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f5.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f6.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f7.xpm") != 0)
		return (1);
	if (check_torch_file("./sprites/torch/f8.xpm") != 0)
		return (1);
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
	game->torch.animation_speed = 2;
	game->torch.width = game->torch.frames[0].w;
	game->torch.height = game->torch.frames[0].h;
	printf("Width: %d\n", game->torch.width);
	printf("Height: %d\n", game->torch.height);
	/*game->torch.img_h = (int)(SCREEN_Y * 0.3);*/
	/*game->torch.img_w = (int)((game->torch.width * game->torch.img_h)*/
	/*						/ game->torch.height);*/
	game->image_torch.img = mlx_new_image(game->mlx.mlx, game->torch.width,
						game->torch.height);
	game->image_torch.data = mlx_get_data_addr(game->image_torch.img,
			&game->image_torch.bpp, &game->image_torch.len,
											&game->image_torch.endian);
	/*paint_torch_frame(game);*/
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->image_torch.img, SCREEN_X - game->torch.width - 10,
						 SCREEN_Y - game->torch.height);
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
		if (game->torch.current < 8)
			game->torch.current++;
		else
			game->torch.current = 0;
	}
	clear_image(game->torch.width, game->torch.height, 0,
		  &game->image_torch);
	paint_torch_frame(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->image_torch.img, SCREEN_X - game->torch.width - 10,
		SCREEN_Y - game->torch.height);
}

void	put_torch_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= game->torch.width || y >= game->torch.height || x < 0 || y < 0)
		return ;
	index = y * game->image_torch.len + x * game->image_torch.bpp / 8;
	game->image_torch.data[index] = color & 0xFF;
	game->image_torch.data[index + 1] = (color >> 8) & 0xFF;
	game->image_torch.data[index + 2] = (color >> 16) & 0xFF;
}

void	paint_torch_frame(t_game *game)
{
	int		x_dst;
	int		y_dst;
	int		current;
	int		color;
	/*double	ratio_x;*/
	/*double	ratio_y;*/

	current = game->torch.current;
	ft_memset(game->image_torch.data, 0,
		game->image_torch.len * game->torch.height);
	/*ratio_x = (double)game->torch.width / (double)game->torch.img_w;*/
	/*ratio_y = (double)game->torch.height / (double)game->torch.img_h;*/
	y_dst = 0;
	while (y_dst < game->torch.height)
	{
		x_dst = 0;
		while (x_dst < game->torch.width)
		{
			color = *(int *)(game->torch.frames[current].data
				+ (y_dst * game->torch.frames[current].line_len)
				+ (x_dst * (game->torch.frames[current].bpp / 8)));
			printf("Color: 0x%06X\n", color);
			if (color != 0)
				put_torch_pixel(x_dst, y_dst, color, game);
			x_dst++;
		}
		y_dst++;
	}
}
