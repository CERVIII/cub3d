/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/09 14:02:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_heigh(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	j;
	int	width;

	width = INT_MIN;
	while (*map)
	{
		j = 0;
		while ((*map)[j])
			j++;
		if (width < j)
			width = j;
		map++;
	}
	return (width);
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
			data->map[i + 1][j] = map[i][j];
			j++;
		}
		i++;
	}
	return ;
}

void	check_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != '1' && map[i][j] != '0')
				ft_error(ERR_CMAP, data, NULL);
			j++;
		}
		i++;
	}
}

void	parser_map(t_data *data)
{
	char	**map;

	map = data->file + 6;
	init_map(data, map);
	check_map(data->map, data);
}
