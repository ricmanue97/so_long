/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:03:47 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/03 11:03:25 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(t_game *game, int move_x, int move_y)
{

}

int	ft_key_register(int keycode, t_game *game)
{
	int move_player;

	if (keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_a)
		move_player = ft_move(game, -1, 0);
	else if (keycode == XK_w)
		move_player = ft_move(game, 0, -1);
	else if (keycode == XK_s)
		move_player = ft_move(game, 0, 1);
	else if (keycode == XK_d)
		move_player = ft_move(game, 0, 1);
	else
		return (0);
	if (move_player == 1)
	{
		ft_printf("Congrats, finished with %d steps", game->player->moves);
		ft_exit(game);
	}
	put_image_to_window(game);
	return (0);
}

