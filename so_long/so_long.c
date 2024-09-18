/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:27:53 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/18 13:02:51 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game		*game;
	t_map		*map;
	t_player	*player;

	game->map = &map;
	game->player = &player;

	if (ac == 2)
	{
		ft_file_check(av[1], &game);
		game->map->path = av[1];
		ft_map_check(&game);

		free(game->map->map_ber);
	}
	else
}
