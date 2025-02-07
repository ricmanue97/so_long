/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:17 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/07 12:00:28 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map->map_ber)
		exit(0);
	i = 0;
	while (i <= game->map->map_height)
	{
		free(game->map->map_ber[i]);
		i++;
	}
	free(game->map->map_ber);
}
void	ft_free_map_dup(char **map)
{
	int	i;

	if (!map)
		exit(0);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error_management(char *message, t_game *game)
{
	ft_printf("%s", message);
	ft_free_map(game);
	exit(1);
}

int	ft_exit(t_game *game)
{
	ft_free_map(game);
	mlx_destroy_image(game->mlx, game->map->img_exit);
	mlx_destroy_image(game->mlx, game->map->floor);
	mlx_destroy_image(game->mlx, game->map->player);
	mlx_destroy_image(game->mlx, game->map->collectible);
	mlx_destroy_image(game->mlx, game->map->wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
	return (0);
}
