/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:17:22 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/03 11:34:34 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_sprites(t_game *game)
{
	int height;
	int width;

	game->map->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor_1.xpm",
		&width, &height);
	if (!game->map->floor)
		ft_error_management("Error : floor sprite not initialised\n", game);
	game->map->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
		&width, &height);
	if (!game->map->player)
		ft_error_management("Error : player sprite not initialised\n", game);
	game->map->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
		&width, &height);
	if (!game->map->img_exit)
		ft_error_management("Error : exit sprite not initialised\n", game);
	game->map->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
		&width, &height);
	if (!game->map->wall)
		ft_error_management("Error : wall sprite not initialised\n", game);
	game->map->collectible = mlx_xpm_file_to_image(game->mlx,
		"sprites/collictible.xpm",&width, &height);
	if (!game->map->collectible)
		ft_error_management("Error : collictible sprite not initialised\n",
			game);
}

static void	ft_put_img(t_game *game, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->map->floor, x, y);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->collectible, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->map->player, x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->map->img_exit, x, y);

}
void	ft_sprites_in_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->map_height)
	{
		j = 0;
		while (j < game->map->map_width)
		{
			ft_put_img(game, game->map->map_ber[i][j], (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}


void	ft_game_interface(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_management("Error : mlx not initialised\n", game);
	game->win = mlx_new_window(game->mlx, (game->map->map_width * 64),
			(game->map->map_height * 64), "So_long");
	init_img_to_mlx(game);
	put_image_to_window(game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, ft_free_map, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_key_register, game);
	mlx_loop(game->mlx);
}
