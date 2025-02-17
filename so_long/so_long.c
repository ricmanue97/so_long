/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:27:53 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/17 17:17:29 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_map		map;
	t_player	player;

	game.map = &map;
	game.player = &player;
	if (ac == 2)
	{
		ft_file_check(av[1]);
		game.map->path = av[1];
		ft_map_creation(&game);
			game.player_count = 0;
		game.exit = 0;
		game.collectible = 0;
		game.player->moves = 0;
		ft_map_check(&game);
		ft_game_interface(&game);
		free(game.map->map_ber);
	}
	else
	{
		ft_printf("Error : not the right amount of arguments");
		return (0);
	}
	return (0);
}
