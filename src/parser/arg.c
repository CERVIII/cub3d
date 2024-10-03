/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:23 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/03 14:29:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error(ERR_ARG, NULL, NULL);
	if (ft_strlen(argv[1]) < 4)
		ft_error(ERR_NAME, NULL, NULL);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4))
		ft_error(ERR_EXT, NULL, NULL);
	return ;
}

void	check_file(char *argv, t_data *data)
{

	if (access(argv, F_OK) == -1)
		ft_error(ERR_FD, NULL, argv);
	if (access(argv, R_OK) == -1)
		ft_error(ERR_READ, NULL, argv);
	data->fd = open(argv, O_RDONLY);
	if (data->fd == -1)
		ft_error(ERR_OPEN, NULL, argv);
}

void	read_write_file(t_data *data)
{
	char	*newline;
	char	*strmap;
	char	*aux;

	newline = get_next_line(data->fd);
	if (!newline)
		ft_error(ERR_EMPTY, NULL, NULL);
	aux = ft_strdup("");
	strmap = ft_strjoin(aux, newline);
	free(aux);
	while (1)
	{
		free(newline);
		newline = get_next_line(data->fd);
		if (!newline)
			break ;
		aux = ft_strdup(strmap);
		free(strmap);
		strmap = ft_strjoin(aux, newline);
		free(aux);
	}
	data->file = ft_split(strmap, '\n');
	free(strmap);
	free(newline);
	close(data->fd);
}

void	check_texture(t_data *data)
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
	char	*aux;
	int		i;
	int		num;

	result = (int *)ft_calloc(sizeof(int), 3);
	cpyline = ft_split(texture, ' ');
	aux = ft_strtrim(cpyline[1], " \t\n\r");
	i = 0;
	while (cpyline[i])
		free(cpyline[i++]);
	free(cpyline);
	cpyline = ft_split(aux, ',');
	i = 0;
	while (i < 3)
	{
		num = ft_atoi(cpyline[i]);
		if (num >= 0 && num <= 255)
			result[i] = num;
		else
			ft_error(ERR_COL, data, NULL);
		i++;
	}
	return (result);
}

void	parser(int argc, char **argv, t_data *data)
{
	check_arg(argc, argv);
	check_file(argv[1], data);
	read_write_file(data);
	check_texture(data);
	return ;
}

