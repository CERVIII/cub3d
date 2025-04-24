/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:21 by pcervill          #+#    #+#             */
/*   Updated: 2025/04/24 19:42:57 by mpenas-z         ###   ########.fr       */
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

	data->heigh = get_heigh(map) + 2;
	data->width = get_width(map) + 2;
	data->map = (char **)ft_calloc(sizeof(char *), data->heigh + 1);
	i = 0;
	while (i < data->heigh)
	{
		j = 0;
		data->map[i] = (char *)ft_calloc(sizeof(char), data->width + 1);
		while (j < data->width)
			data->map[i][j++] = ' ';
		i++;
	}
	copy_map(data, map);
	return ;
}

void	parser_map(t_data *data)
{
	char	**map;

	map = data->file + 6;
	init_map(data, map);
	check_map(data->map, data);
	check_wall(data->map, data);
}
