/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:42 by pcervill          #+#    #+#             */
/*   Updated: 2024/10/15 12:24:28 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	int		heigh;
	int		width;
	char	**map;
	int		pos_player_x;
	int		pos_player_y;
}	t_game;

#endif