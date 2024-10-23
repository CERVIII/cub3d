/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:46:16 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


/* void ft_draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int	step;
	int	x;
	int	y;
	int	i;
	int	delta_x;
	int	delta_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (abs(delta_x) >= abs(delta_y))
		step = abs(delta_x);
	else
		step = abs(delta_y);
	delta_x = delta_x / step;
	delta_y = delta_y / step;
	x = x1;
	y = x2;
	i = 0;
	while (i < step)
	{
		ft_put_pixel(data, x, y, color);
		x += delta_x;
		y += delta_y;
		i++;
	}
} */

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

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_texture(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
	return ;
}

void	free_all(t_data *data)
{
	if (data->file)
		free_array(data->file);
	if (data->map)
		free_array(data->map);
	free_texture(data);
	return ;
}

int	ft_error(char *error, t_data *data, char *file)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(error, 1);
	if (file)
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(file, 1);
		ft_putstr_fd("]", 1);
	}
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(NORMAL, 1);
	if (data)
		free_all(data);
	exit(EXIT_FAILURE);
}
