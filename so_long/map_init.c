/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/17 11:25:48 by ricmanue         ###   ########.fr       */
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
void	ft_height(t_map *map)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		ft_eror_management("Could not open file", map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	map->map_height = i;
}

void	ft_map_init(t_game *game)
{
	int	fd;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		ft_eror_management("Could not open file", game);
	
}
