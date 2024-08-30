/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:56 by ricmanue          #+#    #+#             */
/*   Updated: 2024/08/30 12:31:50 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define sO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"
#include "X11/X.h"
#include "X11/keysym.h"
#include <stdbool.h>


typedef struct	s_game{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			img_width;
	int			img_height;
}				t_game;

typedef struct	s_player{
	void	*img_player;
	int		x_player;
	int		y_player;
}				t_player;

typedef struct	s_map{
	char		**map;
	void		*img_floor1;
	void		*img_floor2;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	int			map_width;
	int			map_height;
	bool		exit;
}				t_map;




#endif
