/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/03 14:42:25 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	map_check(t_map *map)
{
	int	i;
	int	count;
	t_map *tmp;

	tmp = map;
	i = -1;
	while(tmp->map_ber[0][i++])
	{
		count = ft_strlen(tmp->map_ber[i]);
		if (tmp->map_ber[0][i] != '1')
			perror("Map has to be surrounded by walls\n");
	}
	i = -1;
	while(tmp->map_ber[++i])
	{
		if (tmp->map_ber[i][0] != '1' || tmp->map_ber[i][count] != '1')
			perror("Map has to be surrounded by walls\n");
	}
	while(tmp->map_ber[i - 1][count--])
	{
		if (tmp->map_ber[i][count] != '1')
			perror("Map has to be surrounded by walls\n");
	}
}

void ft_map_init(char *path, t_game *game)
{
	int	fd;
	int	i;
	char *line;
	t_map	*map;

	i= 0;
	game->map->map_ber = malloc(sizeof(char **));
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		game->map->map_ber[i] = line;
		i++;
		free(line);
	}
	map_check(game->map);
}
