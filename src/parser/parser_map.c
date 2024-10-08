/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:10:21 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/08 12:20:28 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	parser_map(t_data *data)
{
	copy_map(data);
}
