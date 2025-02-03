/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:44:53 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/03 10:55:03 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_init(t_game *game)
{
	ft_which_sprite(game, game->map->player, "./sprites/test1.xpm");
	ft_which_sprite(game, game->map->floor, "./sprites/floor1.xpm");
	ft_which_sprite(game, game->map->wall, "./sprites/wall.xpm");
	ft_which_sprite(game, game->map->collectible, "./sprites/collictible.xpm");
	ft_which_sprite(game, game->map->img_exit, "./sprites/exit.xpm");
}

void	ft_which_sprite(t_game *game, void **img, char *path)
{
	int	img_width;
	int	img_height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!*img)
	ft_error_management("Error: mlx_xpm_file_to_image failed", game);
}

void	ft_game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_management("Error: Unable to start mlx", game);
	game->player->moves = 0;
	ft_image_init(game);
	game->win = mlx_new_window(game->mlx, game->map->map_width, game->map->map_height, "Catch them all!!");
	if (!(game->win))
		ft_error_management("Error: Could not open window", game);
}
