/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:50 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/02 20:52:31 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_bonus.h"

void	init_key(t_keys *key)
{
	key->a = 0;
	key->w = 0;
	key->s = 0;
	key->d = 0;
	key->left = 0;
	key->right = 0;
	key->esc = 0;
	key->last_mouse_pos = -1;
	key->mouse_inside = 0;
}

void	init_game(t_game *game)
{
	int	x;
	int	y;

	game->map = game->data.map;
	game->heigh = game->data.heigh;
	game->width = game->data.width;
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.05;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("NSEW", game->map[y][x]))
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
				get_direction(game, game->map[y][x]);
			}
			x++;
		}
		y++;
	}
	init_key(&game->keys);
}

int	handle_loop(t_game *game)
{
	clear_image(SCREEN_X, SCREEN_Y, 0, &game->image);
	clear_image(MINIMAP_X, MINIMAP_Y, 1, &game->image_minimap);
	ft_memset(game->image.data, 0, SCREEN_X * SCREEN_Y * (game->image.bpp / 8));
	handle_movements(game);
	if (MINIMAP)
	{
		ft_memset(game->image_minimap.data, 0xFFFFFF,
			game->image_minimap.len * MINIMAP_Y);
		print_map2d(game);
		print_player(game->data.player_xpx, game->data.player_ypx, game);
	}
	raycasting(game);
	torch_loop(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->image.img, 0, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->image_minimap.img, 10, 10);
	return (0);
}

void	init_mlx(t_mlx *mlx, t_img *image, t_img *image_minimap)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREEN_X, SCREEN_Y, NAME);
	image->img = mlx_new_image(mlx->mlx, SCREEN_X, SCREEN_Y);
	image_minimap->img = mlx_new_image(mlx->mlx, MINIMAP_X, MINIMAP_Y);
	image->data = mlx_get_data_addr(image->img,
			&image->bpp, &image->len, &image->endian);
	image_minimap->data = mlx_get_data_addr(image_minimap->img,
			&image_minimap->bpp, &image_minimap->len, &image_minimap->endian);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, image->img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, image_minimap->img, 10, 10);
}

void	ft_game(t_game *game)
{
	init_game(game);
	game->player.mouse_speed = 0.005;
	init_mlx(&game->mlx, &game->image, &game->image_minimap);
	load_wall_textures(game);
	init_torch(game);
	mlx_hook(game->mlx.mlx_win, DESTROY, 0, &end_program, game);
	mlx_hook(game->mlx.mlx_win, MOUSE, (1L << 6), &mouse_move, game);
	mlx_hook(game->mlx.mlx_win, KEY_PRESS, (1L << 0), &pulse_key, game);
	mlx_hook(game->mlx.mlx_win, KEY_OFF, (1L << 1), &release_key, game);
	mlx_loop_hook(game->mlx.mlx, &handle_loop, game);
	mlx_loop(game->mlx.mlx);
}
