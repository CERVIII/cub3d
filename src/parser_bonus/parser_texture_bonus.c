/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:23 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/03 12:50:21 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*save_texture(char *texture, t_data *data)
{
	char	**cpyline;
	char	*result;
	char	*aux;
	int		i;
	int		fd;

	cpyline = ft_split(texture, ' ');
	aux = ft_strtrim(cpyline[1], " \t\n\r");
	result = ft_strdup(aux);
	i = 0;
	while (cpyline[i])
		free(cpyline[i++]);
	free(cpyline);
	free(aux);
	if (ft_strncmp(result + ft_strlen(result) - 4, ".xpm", 4) != 0)
		ft_error(ERR_XPMEXT, data, result);
	fd = open(result, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_OPEN, data, result);
	aux = get_next_line(fd);
	if (!aux)
		ft_error(ERR_EMPTY, data, result);
	free(aux);
	return (result);
}

int	*save_color(char *texture, t_data *data)
{
	char	**cpyline;
	int		*result;
	char	*line;
	int		i;

	result = (int *)ft_calloc(sizeof(int), 3);
	line = ft_substr(texture, 1, (ft_strlen(texture) - 1));
	cpyline = ft_split(line, ',');
	free(line);
	if (get_heigh(cpyline) != 3)
		ft_error(ERR_NCOL, data, NULL);
	i = -1;
	while (++i < 3)
	{
		if (ft_atoi(cpyline[i]) >= 0 && ft_atoi(cpyline[i]) <= 255)
			result[i] = ft_atoi(cpyline[i]);
		else
		{
			free_array(cpyline);
			ft_error(ERR_COL, data, NULL);
		}
	}
	free_array(cpyline);
	return (result);
}

void	parser_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(data->file[i], "NO ", 3) == 0)
			data->no = save_texture(data->file[i], data);
		else if (ft_strncmp(data->file[i], "SO ", 3) == 0)
			data->so = save_texture(data->file[i], data);
		else if (ft_strncmp(data->file[i], "WE ", 3) == 0)
			data->we = save_texture(data->file[i], data);
		else if (ft_strncmp(data->file[i], "EA ", 3) == 0)
			data->ea = save_texture(data->file[i], data);
		else if (ft_strncmp(data->file[i], "F ", 2) == 0)
			data->f = save_color(data->file[i], data);
		else if (ft_strncmp(data->file[i], "C ", 2) == 0)
			data->c = save_color(data->file[i], data);
		else
			ft_error(ERR_TEXT, data, NULL);
		i++;
	}
	if (check_texture_file("./textures/door_texture.xpm") != 0)
		ft_error("Door texture required in bonus!", data, NULL);
}

int	check_texture_file(char *path)
{
	int	temp_fd;

	temp_fd = open(path, O_RDONLY);
	if (temp_fd == -1)
		ft_error(ERR_OPEN, NULL, path);
	return (close(temp_fd), 0);
}
