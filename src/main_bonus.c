/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:32:09 by pcervill          #+#    #+#             */
/*   Updated: 2025/05/06 20:10:00 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
	printf("_____________________________________________________________\n");
	return ;
}

void	print_texture(t_data *data)
{
	printf("%s\n", data->no);
	printf("%s\n", data->so);
	printf("%s\n", data->we);
	printf("%s\n", data->ea);
	printf("R: %d	G: %d	B: %d\n", data->f[0], data->f[1], data->f[2]);
	printf("R: %d	G: %d	B: %d\n", data->c[0], data->c[1], data->c[2]);
	printf("_____________________________________________________________\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_data(&game.data);
	parser(argc, argv, &game.data);
	ft_game(&game);
	free_all(&game.data);
	return (0);
}
