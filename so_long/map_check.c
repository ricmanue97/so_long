/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:09:13 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/12 15:38:16 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_check (char *file, t_game *game)
{
	size_t len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp((&file[len - 4]), ".ber", 4) != 0)
	{
		ft_printf("Error : not ber file");
		free_game(game);
		exit(1);
	}
}

void	ft_wall_check (t_game *game)
{
	int i;

	i = 0;
	while (i < game->map->map_width)
	{
		if ((game->map->map_ber[0][i] == 1)
			&& game->map->map_ber[game->map->map_height - 1][i] == 1)
			i++;
		else
			ft_error_management("Error : map frame\n", game);
	}
	i = 1;
	while (i < game->map->map_height - 1)
	{
		if ((game->map->map_ber[i][0] == 1)
			&& game->map->map_ber[game->map->map_width - 1][i] == 1)
			i++;
		else
			ft_error_management("Error : map frame\n", game);
	}
}

void	ft_sprite_limit_check(t_game *game, int i, int j)
{
	char	*ber_array;

	ber_array = game->map->map_ber[i];
	while (j < game->map->map_width)
	{
		if ((ber_array[j] != 0) && (ber_array[j] != 1) && (ber_array[j] != 'P')
			&& (ber_array[j] != 'C') && (ber_array[j] != 'E'))
			ft_error_management("Error : ivalid sprite\n", game);
		if (ber_array[j] == 'P')
			game->player++;
		else if (ber_array[j] == 'C')
			game->collectible++;
		else if (ber_array[j] == 'E')
			game->exit++;
		j++;
	}
}
void	map_check(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map->map_height)
	{
		ft_sprite_limit_check(game, i, 0);
		if ((game->player > 1) || (game->exit > 1))
		ft_error_management("Error : too many players or exits\n", game);
		i++;
	}
}
