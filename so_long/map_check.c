/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:09:13 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/07 11:38:46 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_check(char *file, t_game *game)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp((&file[len - 4]), ".ber", 4) != 0)
	{
		ft_error_management("Error : not ber file", game);
		ft_free_map(game);
		exit(1);
	}
}

void	ft_wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->map_width)
	{
		if ((game->map->map_ber[0][i] == '1')
			&& game->map->map_ber[game->map->map_height][i] == '1')
			i++;
		else
			ft_error_management("Error : map frame\n", game);
	}
	i = 1;
	while (i < game->map->map_height)
	{
		if ((game->map->map_ber[i][0] == '1')
			&& game->map->map_ber[i][game->map->map_width] == '1')
			i++;
		else
			ft_error_management("Error : map frame\n", game);
	}
}

void	ft_sprite_limit_check(t_game *game, int i, int j)
{
	char	*ber_array;

	ber_array = game->map->map_ber[i];
	while (j <= game->map->map_width)
	{
		if ((ber_array[j] != '0') && (ber_array[j] != '1') && (ber_array[j] != 'P')
			&& (ber_array[j] != 'C') && (ber_array[j] != 'E'))
			ft_error_management("Error : ivalid sprite\n", game);
		if (ber_array[j] == 'P')
		{
			game->player_count++;
			game->player->x = j;
			game->player->y = i;
		}
		else if (ber_array[j] == 'C')
			game->collectible = game->collectible + 1;
		else if (ber_array[j] == 'E')
			game->exit++;
		j++;
	}
}

void	ft_map_sprite_check(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map->map_height)
	{
		ft_sprite_limit_check(game, i, 0);
		if ((game->player_count > 1) || (game->exit > 1))
			ft_error_management("Error : too many players or exits\n", game);
		i++;
	}
}

void	ft_map_check(t_game *game)
{
	int	i;
	int	len;

	if (game->map->map_ber[0] == NULL)
		ft_error_management("Error : map file is empty\n", game);
	i = 0;
	len = ft_strlen(game->map->map_ber[0]) - 1;
	game->map->map_width = len;
	while (i < game->map->map_height)
	{
		len = ft_strlen(game->map->map_ber[i]) - 1;
		if (len != game->map->map_width)
			ft_error_management("Error : map is not rectangular\n", game);
		i++;
	}
	game->map->map_width--;
	ft_wall_check(game);
	game->player_count = 0;
	game->exit = 0;
	game->collectible = 0;
	game->player->moves = 0;
	ft_map_sprite_check(game);
	ft_valid_map(game);
	ft_exit_position(game);
}
