/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:56 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/30 12:25:04 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "X11/X.h"
#include "X11/keysym.h"
#include "mlx_linux/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"


typedef struct	s_player{
	int		x_player;
	int		y_player;
	int		moves;
}				t_player;

typedef struct	s_map{
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

typedef struct	s_game{
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
void	ft_file_check (char *file, t_game *game);
void	ft_wall_check (t_game *game);
void	ft_sprite_limit_check(t_game *game, int i, int j);
void	ft_map_sprite_check(t_game *game);
void	ft_map_check(t_game *game);
void	ft_map_ber(t_game *game, int fd, int map_height);
void	ft_map_init(t_game *game);
void	ft_valid_map(t_game *game);
#endif
