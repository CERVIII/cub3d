/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:32:09 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/03 16:18:17 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	return ;
}

void	print_texture(t_data *data)
{
	printf("%s\n", data->no);
	printf("%s\n", data->so);
	printf("%s\n", data->we);
	printf("%s\n", data->ea);
	printf("%d,%d,%d\n", data->f[0], data->f[1], data->f[2]);
	printf("%d,%d,%d\n", data->c[0], data->c[1], data->c[2]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	parser(argc, argv, &data);
//	print_texture(&data);
//	print_map(&data);
	free_all(&data);
	return (0);
}
