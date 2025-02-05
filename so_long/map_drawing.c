/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:52:36 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/05 13:30:36 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_drawing(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = game->map->map_ber;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (game->map->map_ber[i][j] == '1')
				ft_sprite_set(game, game->map->wall, i, j);
			if (game->map->map_ber[i][j] == '0' )
				ft_sprite_set(game, game->map->floor, i, j);
			if (game->map->map_ber[i][j] == 'C' )
				ft_sprite_set(game, game->map->collectible, i, j);
			if (game->map->map_ber[i][j] == 'P' )
				ft_sprite_set(game, game->map->player, i, j);
			if (game->map->map_ber[i][j] == 'E' )
				ft_sprite_set(game, game->map->img_exit, i, j);
			j++;
		}
		i++;
	}
}

void	ft_sprite_set(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img, i, j);
}
