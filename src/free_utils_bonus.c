/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpenas-z <mpenas-z@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:39:31 by mpenas-z          #+#    #+#             */
/*   Updated: 2025/06/03 11:02:50 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
