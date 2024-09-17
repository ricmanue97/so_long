/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:23:42 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/17 16:32:14 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(int i, int j, char **map_ber, t_map *map)
{
	if (i < 0 || (i >= map->map_height) || (j < 0 || j >map->map_width -1))
		return ;
	if (map_ber[i][j] != '1' && map_ber[i][j] != 'F')
	{
		map_ber[i][j] = 'F';
		ft_flood_fill(i - 1, j, map_ber, map);
		ft_flood_fill(i + 1, j, map_ber, map);
		ft_flood_fill(i, j - 1, map_ber, map);
		ft_flood_fill(i, j + 1, map_ber, map);
	}

}

