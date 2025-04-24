/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:42:12 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/04/24 19:42:53 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(char **map, int x, int y, t_data *data)
{
	if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		data->player_xpx = (x * WALL_SIZE) + (WALL_SIZE / 2);
		data->player_x = x + 0.5;
		data->player_ypx = (y * WALL_SIZE) + (WALL_SIZE / 2);
		data->player_y = y + 0.5;
		return (1);
	}
	return (0);
}

void	check_map(char **map, t_data *data)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != ' ' && map[y][x] != 'N' && map[y][x] != 'S'
				&& map[y][x] != 'E' && map[y][x] != 'W'
				&& map[y][x] != '1' && map[y][x] != '0')
				ft_error(ERR_CMAP, data, NULL);
			player += check_player(map, x, y, data);
		}
	}
	if (player > 1)
		ft_error(ERR_MPL, data, NULL);
	if (player < 1)
		ft_error(ERR_NPL, data, NULL);
	return ;
}

void	check_wall(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (map[y - 1][x] == ' ' || map[y][x - 1] == ' '
					|| map[y + 1][x] == ' ' || map[y][x + 1] == ' ')
					ft_error(ERR_WMAP, data, NULL);
			}
			x++;
		}
		y++;
	}
}
