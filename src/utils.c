/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:46:16 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/01 15:11:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_data(t_data *data)
{
	data->fd = 0;
	return ;
}

void	free_all(t_data *data)
{
	free(data->map);
	free(data);
}

int	ft_error(char *error, t_data *data)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd(NORMAL, 1);
	if (data)
		free_all(data);
	exit(EXIT_FAILURE);
}
