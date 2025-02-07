/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:56 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/07 11:58:43 by ricmanue         ###   ########.fr       */
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

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}				t_player;

typedef struct s_map
{
	char		**map_ber;
	char		*path;
	void		*floor;
	void		*player;
	void		*wall;
	void		*collectible;
	void		*img_exit;
	int			x_exit;
	int			y_exit;
	int			map_width;
	int			map_height;
	bool		error;
	bool		exit;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			exit;
	int			player_count;
	int			collectible;
}				t_game;

void	ft_free_map(t_game *game);
void	ft_error_management(char *message, t_game *game);
int		ft_exit(t_game *game);
void	ft_sprites_in_window(t_game *game);
void	ft_game_interface(t_game *game);
void	ft_file_check(char *file, t_game *game);
void	ft_wall_check(t_game *game);
void	ft_sprite_limit_check(t_game *game, int i, int j);
void	ft_map_sprite_check(t_game *game);
void	ft_map_check(t_game *game);
void	ft_map_drawing(t_game *game);
void	ft_sprite_set(t_game *game, void *img, int i, int j);
int		ft_key_register(int keycode, t_game *game);
void	ft_valid_map(t_game *game);
void	ft_map_creation(t_game *game);
void	ft_exit_position(t_game *game);
void	ft_free_map_dup(char **map);

#endif
