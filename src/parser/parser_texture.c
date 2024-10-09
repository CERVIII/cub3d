/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:23 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/09 15:02:41 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*save_texture(char *texture, t_data *data)
{
	char	**cpyline;
	char	*result;
	char	*aux;
	int		i;

	cpyline = ft_split(texture, ' ');
	aux = ft_strtrim(cpyline[1], " \t\n\r");
	result = ft_strdup(aux);
	i = 0;
	while (cpyline[i])
		free(cpyline[i++]);
	free(cpyline);
	free(aux);
	if (access(result, F_OK) == -1)
		ft_error(ERR_FD, data, result);
	if (access(result, R_OK) == -1)
		ft_error(ERR_READ, data, result);
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
}
