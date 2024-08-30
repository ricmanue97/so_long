/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/08/30 17:11:10 by ricmanue         ###   ########.fr       */
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
int mapveri(t_game *game)
{
	int i;
	int j;

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
	map_veri(game);
}
