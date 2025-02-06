/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:27:53 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/06 10:43:08 by ricmanue         ###   ########.fr       */
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
		ft_file_check(av[1], &game);
		game.map->path = av[1];
		ft_map_creation(&game);
		ft_map_check(&game);
		ft_game_interface(&game);
		free(game.map->map_ber);
	}
	else
	{
		ft_printf("Not the right amount of arguments");
		return (0);
	}
	return (0);
}
