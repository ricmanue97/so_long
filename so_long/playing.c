/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:03:47 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/06 16:17:52 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move(t_game *game, int move_x, int move_y)
{
	char	next;
	char	current;

	next = game->map->map_ber[(game->player->y) + move_y]
	[(game->player->x) + move_x];
	current = game->map->map_ber[(game->player->y)][(game->player->x)];
	if (next != '1')
	{
		game->player->moves++;
		ft_printf("moves->%d\n", game->player->moves);
		if (next == 'C')
			game->collectible--;
		game->map->map_ber[(game->player->y)][(game->player->x)] = '0';
		if (current != 'E')
		{
			game->map->map_ber[(game->player->y)][(game->player->x)] = '0';
			game->map->map_ber[(game->map->y_exit)][(game->map->x_exit)] = 'E';
		}
		game->map->map_ber[(game->player->y) + move_y][(game->player->x) + move_x] = 'P';
		game->player->x = game->player->x + move_x;
		game->player->y = game->player->y + move_y;
		if ((next == 'E') && (game->collectible == 0))
			return (1);
	}
	return (0);
}

int	ft_key_register(int keycode, t_game *game)
{
	int	move_player;

	if (keycode == XK_Escape)
		ft_exit(game);
	if (keycode == XK_a)
		move_player = ft_move(game, -1, 0);
	else if (keycode == XK_w)
		move_player = ft_move(game, 0, -1);
	else if (keycode == XK_s)
		move_player = ft_move(game, 0, 1);
	else if (keycode == XK_d)
		move_player = ft_move(game, 1, 0);
	else
		return (0);
	if (move_player == 1)
	{
		ft_printf("Congrats, caught them all with %d steps",
			game->player->moves);
		ft_exit(game);
	}
	ft_sprites_in_window(game);
	return (0);
}
