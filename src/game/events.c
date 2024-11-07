/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:45:15 by pcervill          #+#    #+#             */
/*   Updated: 2024/11/07 13:19:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	end_program(void *l)
{
	(void)l;
	exit(0);
}

int	pulse_key(int key, t_game *game)
{
	if (key == ESC || key == ESC_L)
		end_program(game);
	if (key == A || key == A_L)
		game->keys.a = 1;
	if (key == W || key == W_L)
		game->keys.w = 1;
	if (key == S || key == S_L)
		game->keys.s = 1;
	if (key == D || key == D_L)
		game->keys.d = 1;
	if (key == LEFT || key == L)
		game->keys.left = 1;
	if (key == RIGHT || key == R)
		game->keys.right = 1;
	return (0);
}

int	release_key(int key, t_game *game)
{
	if (key == A || key == A_L)
		game->keys.a = 0;
	if (key == W || key == W_L)
		game->keys.w = 0;
	if (key == S || key == S_L)
		game->keys.s = 0;
	if (key == D || key == D_L)
		game->keys.d = 0;
	if (key == LEFT || key == L)
		game->keys.left = 0;
	if (key == RIGHT || key == R)
		game->keys.right = 0;
	return (0);
}
