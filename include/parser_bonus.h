/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:50:33 by pcervill          #+#    #+#             */
/*   Updated: 2025/06/03 12:49:42 by mpenas-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

/* ERROR */
# define ERR_ARG "Not valid arguments"
# define ERR_NAME "The name is very short"
# define ERR_EXT "The .cub extension is needed"
# define ERR_XPMEXT "The .xpm extension is needed in textures"
# define ERR_FD "The file does not exist "
# define ERR_READ "Do not have permission to read this file "
# define ERR_OPEN "Error opening file "
# define ERR_LMAP "Empty line in map is not allowed."
# define ERR_EMPTY "Empty file "
# define ERR_TEXT "Invalid value for textures and colors"
# define ERR_NCOL "Value for colors must be in R,G,B"
# define ERR_COL "Floor or ceiling value's are not numbers"
# define ERR_CMAP "Invalid characters detected"
# define ERR_WMAP "Invalid map, not closed"
# define ERR_DMAP "Invalid map, door not between walls"
# define ERR_NPL "No player position detected"
# define ERR_MPL "Multiple player position detected"

typedef struct s_data
{
	int		fd;
	char	**file;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		heigh;
	int		width;
	double	player_xpx;
	double	player_x;
	double	player_ypx;
	double	player_y;
}	t_data;

/* PARSER.C */
void	parser(int argc, char **argv, t_data *data);

/* PARSER_FILE.C */
void	check_arg(int argc, char **argv);
void	check_file(char *argv, t_data *data);
void	verify_blank_line(char *line);
void	read_write_file(t_data *data);
void	parser_file(int argc, char **argv, t_data *data);

/* PARSER_TEXTURE.C */
char	*save_texture(char *texture, t_data *data);
int		*save_color(char *texture, t_data *data);
void	parser_texture(t_data *data);
int		check_texture_file(char *path);

/* PARSER_MAP.C */
void	copy_map(t_data *data, char **map);
void	init_map(t_data *data, char **map);

/* PARSER_CHECK.C */
void	check_map(char **map, t_data *data);
void	check_wall(char **map, t_data *data);
void	parser_map(t_data *data);

#endif
