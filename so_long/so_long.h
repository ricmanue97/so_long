/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:56 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/17 11:12:59 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"
#include "X11/X.h"
#include "X11/keysym.h"
#include <stdbool.h>
#include "./get_next_line/get_next_line.h"

typedef struct	s_game{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			img_width;
	int			img_height;
	int			player;
	int			exit;
	int			collectible;
}				t_game;

typedef struct	s_player{
	void	*img_player;
	int		x_player;
	int		y_player;
}				t_player;

typedef struct	s_map{
	char		**map_ber;
	char		*path;
	void		*img_floor1;
	void		*img_floor2;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	int			map_width;
	int			map_height;
	bool		error;
	bool		exit;
}				t_map;




#endif
