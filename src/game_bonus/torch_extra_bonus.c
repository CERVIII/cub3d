/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:47:17 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/06/03 12:08:31 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	torch_loop(t_game *game)
{
	if (game->torch_on == 0)
		return ;
	game->torch.animation_count++;
	if (game->torch.animation_count >= game->torch.animation_speed)
	{
		game->torch.animation_count = 0;
		if (game->torch.current < game->torch.frame_count - 1)
			game->torch.current += 1;
		else
			game->torch.current = 0;
	}
	print_torch(game->torch.current, game);
}

void	print_scaled_pixel(int x, int y, int scale, t_game *game)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;

	offset_x = SCREEN_X - (int)(game->torch.scale * game->torch.width) - 10;
	offset_y = SCREEN_Y - (int)(game->torch.scale * game->torch.height) / 3;
	j = 0;
	while (j < scale)
	{
		i = 0;
		while (i < scale)
		{
			if ((x * scale) + i + offset_x >= 0
				&& (x * scale) + i + offset_x < SCREEN_X
				&& (y * scale) + j + offset_y >= 0
				&& (y * scale) + j + offset_y < SCREEN_Y)
				put_pixel((x * scale) + i + offset_x,
					(y * scale) + j + offset_y, game->color, &game->image);
			i++;
		}
		j++;
	}
}

void	print_torch(int current, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->torch.height)
	{
		x = 0;
		while (x < game->torch.width)
		{
			game->color = *(unsigned int *)(game->torch.frames[current].data
					+ (y * game->torch.frames[current].h + x));
			if (game->color != 0x000000)
				print_scaled_pixel(x, y, game->torch.scale, game);
			x++;
		}
		y++;
	}
}

void	swich_door_state(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->data.player_x;
	y = (int)game->data.player_y;
	if (game->map[y - 1][x] == 'C')
		game->map[y - 1][x] = 'O';
	else if (game->map[y - 1][x] == 'O')
		game->map[y - 1][x] = 'C';
	if (game->map[y + 1][x] == 'C')
		game->map[y + 1][x] = 'O';
	else if (game->map[y + 1][x] == 'O')
		game->map[y + 1][x] = 'C';
	if (game->map[y][x - 1] == 'C')
		game->map[y][x - 1] = 'O';
	else if (game->map[y][x - 1] == 'O')
		game->map[y][x - 1] = 'C';
	if (game->map[y][x + 1] == 'C')
		game->map[y][x + 1] = 'O';
	else if (game->map[y][x + 1] == 'O')
		game->map[y][x + 1] = 'C';
}
