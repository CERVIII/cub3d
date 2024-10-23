/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:45:15 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/23 14:13:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	end_program(void *l)
{
	(void)l;
	exit(0);
}

static void	horizontal_movs(t_game *game)
{
	
}

static void	lateral_movs(t_game *game)
{
	
}

static void	rotation_player(t_game *game)
{
	int rotSpeed;

	rotSpeed = 0;
	if (game->keys.left)
		rotSpeed -= game->player.rot_speed;
	else if (game->keys.right)
		rotSpeed -= game->player.rot_speed;
	else
		return ;
	
}

int	handle_movements(t_game *game)
{
	horizontal_movs(game);
	lateral_movs(game);
	rotation_player(game);
}