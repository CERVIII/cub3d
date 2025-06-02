/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:58:58 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/06/02 20:52:20 by mpenas-z         ###   ########.fr       */
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
	game->torch.animation_speed = 5;
	game->torch.width = game->torch.frames[0].w;
	game->torch.height = game->torch.frames[0].h;
	game->torch.scale = (SCREEN_Y * 0.7) / game->torch.height;
	game->torch.img_h = (int)(game->torch.height * game->torch.scale);
	game->torch.img_w = (int)(game->torch.width * game->torch.scale);
	game->torch_on = 1;
}
