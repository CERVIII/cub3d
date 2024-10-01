/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:32:09 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/01 15:22:57 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	parser(argc, argv, &data);
	i = 0;
	while (data.map[i])
		printf("%s\n", data.map[i++]);
	return (0);
}
