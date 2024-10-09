/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/09 12:23:54 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_heigh(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	i;
	int	j;
	int	width;

	width = INT_MIN;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > width)
			width = j;
	}
	return (j);
}


void	init_map(t_data *data)
{
	char	**map;

	map = data->file + 6;
	data->heigh = get_heigh(map);
	data->width = get_width(map);
	printf("heigh: %d	width: %d\n", data->heigh, data->width);
}

void	copy_map(t_data *data)
{
	int		i;
	int		j;

	i = 6;
	j = 0;
	while (data->file[i++])
		j++;
	data->map = (char **)ft_calloc(sizeof(char *), (j + 1));
	i = 6;
	j = 0;
	while (data->file[i])
	{
		data->map[j] = ft_strdup(data->file[i]);
		j++;
		i++;
	}
	return ;
}

/* void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			
		}
	}
} */

void	parser_map(t_data *data)
{
	copy_map(data);
	init_map(data);
//	check_map(data);
}
