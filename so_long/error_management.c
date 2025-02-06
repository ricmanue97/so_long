/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:17 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/06 10:08:32 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		exit(0);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error_management(char *message, t_game *game)
{
	ft_printf("%s", message);
	ft_free_map(game->map->map_ber);
	exit(1);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game->map->map_ber);
	exit (0);
}
