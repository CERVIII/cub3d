/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:46:16 by pcervill          #+#    #+#             */
/*   Updated: 2025/04/24 19:40:25 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

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

void	init_data(t_data *data)
{
	data->fd = 0;
	data->file = NULL;
	data->map = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
	data->heigh = 0;
	data->width = 0;
	data->player_x = 0;
	data->player_y = 0;
	return ;
}
