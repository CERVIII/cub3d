/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:09:40 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/03 11:12:41 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parser(int argc, char **argv, t_data *data)
{
	parser_file(argc, argv, data);
	parser_texture(data);
	parser_map(data);
	return ;
}
