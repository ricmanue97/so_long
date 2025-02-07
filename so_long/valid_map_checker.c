/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:23:42 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/07 12:14:31 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_flood_fill(int i, int j, char **map_ber, t_map *map)
{
	if (i < 0 || j < 0 || i >= map->map_height || j >= map->map_width \
		|| map_ber[i][j] == '1' || map_ber[i][j] == 'F')
		return ;
	map_ber[i][j] = 'F';
	ft_flood_fill(i + 1, j, map_ber, map);
	ft_flood_fill(i - 1, j, map_ber, map);
	ft_flood_fill(i, j + 1, map_ber, map);
	ft_flood_fill(i, j - 1, map_ber, map);
}

static char	**ft_map_duplicate(t_game *game)
{
	int		i;
	char	**map_ber;

	map_ber = malloc((sizeof(char *) * (game->map->map_height + 2)));
	if (!map_ber)
		ft_error_management("Failed memory allocation", game);

	i = 0;
	while (i <= game->map->map_height)
	{
		map_ber[i] = ft_strdup(game->map->map_ber[i]);
		i++;
	}
	map_ber[i]= NULL;
	return (map_ber);
}

void	ft_valid_map(t_game *game)
{
	int		i;
	int		j;
	char	**map_duplicate;

	map_duplicate = ft_map_duplicate(game);
	ft_flood_fill(game->player->y, game->player->x, map_duplicate,
		game->map);
	i = 0;
	while (i <= game->map->map_height)
	{
		j = 0;
		while (j <= game->map->map_width)
		{
			if (map_duplicate[i][j] != '1' && map_duplicate[i][j] != 'F' && map_duplicate[i][j] != '0')
			{
				ft_free_map_dup(map_duplicate);
				ft_error_management("Map does not have solution\n", game);
			}
			j++;
		}
		i++;
	}
	ft_free_map_dup(map_duplicate);
}
