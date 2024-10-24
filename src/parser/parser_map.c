/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/24 14:58:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_data *data, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			data->map[i + 1][j + 1] = map[i][j];
			j++;
		}
		i++;
	}
	return ;
}

void	init_map(t_data *data, char **map)
{
	int		i;
	int		j;

	data->heigh = get_heigh(map) + 3;
	data->width = get_width(map) + 3;
	data->map = (char **)ft_calloc(sizeof(char *), data->heigh);
	i = 0;
	while (i < data->heigh - 1)
	{
		j = 0;
		data->map[i] = (char *)ft_calloc(sizeof(char), data->width);
		while (j < data->width - 1)
			data->map[i][j++] = ' ';
		i++;
	}
	copy_map(data, map);
	return ;
}

int	check_player(char **map, int x, int y, t_data *data)
{
	if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		data->player_xpx = (x * WALL_SIZE) + (WALL_SIZE / 2);
		data->player_x = x;
		data->player_ypx = (y * WALL_SIZE) + (WALL_SIZE / 2);
		data->player_y = y;
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

void	parser_map(t_data *data)
{
	char	**map;

	map = data->file + 6;
	init_map(data, map);
	check_map(data->map, data);
	check_wall(data->map, data);
}
