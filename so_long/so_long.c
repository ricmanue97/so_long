/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:27:53 by ricmanue          #+#    #+#             */
/*   Updated: 2025/01/16 14:11:38 by ricmanue         ###   ########.fr       */
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
		ft_map_init(&game);
		ft_game_init(&game);
		ft_map_check(&game);
		
		free(game->map->map_ber);
	}

}
