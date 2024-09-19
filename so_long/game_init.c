/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:44:53 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/19 11:57:48 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_init(t_game *game)
{
	ft_which_sprite(game, &game->player->img_player, "./test1.xpm");
	ft_which_sprite(game, &game->map->img_floor1, "./floor1.xpm");
	ft_which_sprite(game, &game->map->img_floor2, "./floor2.xpm");
	ft_which_sprite(game, &game->map->img_wall, "./wall.xpm");
}

void	ft_which_sprite(t_game *game, void **img, char *path)
{
	int	img_width;
	int	img_height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &img_width, img_height);
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
