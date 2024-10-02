/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:23 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/02 16:00:14 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		ft_error(ERR_ARG, NULL);
	if (ft_strlen(argv[1]) < 4)
		ft_error(ERR_NAME, NULL);
	if (ft_strncmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4))
		ft_error(ERR_EXT, NULL);
	return ;
}

void	check_file(char *argv, t_data *data)
{

	if (access(argv, F_OK) == -1)
		ft_error(ERR_FD, NULL);
	if (access(argv, R_OK) == -1)
		ft_error(ERR_PERM, NULL);
	data->fd = open(argv, O_RDONLY);
	if (data->fd == -1)
		ft_error(ERR_OPEN, NULL);
}

void	read_write_file(t_data *data)
{
	char	*newline;
	char	*strmap;
	char	*aux;

	newline = get_next_line(data->fd);
	if (!newline)
		ft_error(ERR_EMPTY, NULL);
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
			data->no = save_texture(data->file[i]);
//			data->no = ft_strdup(data->file[i]);
		else if (ft_strncmp(data->file[i], "SO ", 3) == 0)
			data->so = save_texture(data->file[i]);
		else if (ft_strncmp(data->file[i], "WE ", 3) == 0)
			data->we = save_texture(data->file[i]);
		else if (ft_strncmp(data->file[i], "EA ", 3) == 0)
			data->ea = save_texture(data->file[i]);
		else if (ft_strncmp(data->file[i], "F ", 2) == 0)
			data->f = save_texture(data->file[i]);
		else if (ft_strncmp(data->file[i], "C ", 2) == 0)
			data->c = save_texture(data->file[i]);
		else
			ft_error(ERR_TEXT, data);
		i++;
	}
}

char	*save_texture(char *texture)
{
	char	**cpyline;
	char	*result;

	cpyline = ft_split(texture, ' ');
	result = ft_strdup(ft_strtrim(cpyline[1], " \t\n\r"));
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
