/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:44:53 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/18 16:22:26 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_which_sprite(t_game *game)
{


}

void	ft_img_init(t_game *game, void **img, char *path)
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

}
