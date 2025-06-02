/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:04 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/02 14:37:49 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->fd = open(argv, O_RDONLY);
	if (data->fd == -1)
		ft_error(ERR_OPEN, NULL, argv);
}

void	verify_blank_line(char *line)
{
	static unsigned int	count = 0;
	static int			enter = 0;
	static int			exit = 0;
	char				*cpy;

	cpy = ft_strtrim(line, "\t");
	if (count == 6 && ft_strlen(cpy) > 1 && !enter)
		enter = 1;
	if (count < 6 && ft_strlen(cpy) > 1)
		count++;
	if (enter && ft_strlen(cpy) == 1 && !exit)
		exit++;
	if ((ft_strlen(cpy) > 1 || *cpy != '\n') && exit)
		ft_error(ERR_LMAP, NULL, NULL);
	free(cpy);
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
		verify_blank_line(newline);
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
}

void	parser_file(int argc, char **argv, t_data *data)
{
	check_arg(argc, argv);
	check_file(argv[1], data);
	read_write_file(data);
	close(data->fd);
}
