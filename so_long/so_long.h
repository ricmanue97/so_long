/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:56 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/15 11:35:47 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

typedef struct s_player {
	int		x_player;
	int		y_player;
	int		moves;
}				t_player;

typedef struct s_map {
	char		**map_ber;
	char		*path;
	void		*img_floor1;
	void		*img_player;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	int			map_width;
	int			map_height;
	bool		error;
	bool		exit;
}				t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			img_width;
	int			img_height;
	int			player_count;
	int			exit;
	int			collectible;
}				t_game;

void	free_map(char **map);
void	ft_error_management(char *message, t_game *game);
void	ft_image_init(t_game *game);
void	ft_which_sprite(t_game *game, void **img, char *path);
void	ft_game_init(t_game *game);
void	ft_file_check(char *file, t_game *game);
void	ft_wall_check(t_game *game);
void	ft_sprite_limit_check(t_game *game, int i, int j);
void	ft_map_sprite_check(t_game *game);
void	ft_map_check(t_game *game);
void	ft_map_drawing(t_game *game);
void	ft_sprite_set(t_game *game, void *img, int i, int j);
static void	ft_flood_fill(int i, int j, char **map_ber, t_map *map);
static char	**ft_map_duplicate(t_game *game);
void	ft_valid_map(t_game *game);

#endif