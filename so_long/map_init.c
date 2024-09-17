/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/17 15:16:03 by ricmanue         ###   ########.fr       */
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

void	ft_map_ber(t_map *map, int fd, int map_height)
{
	char	**map_line;
	char	*line;
	int		i;

	map_line = malloc(sizeof(char *) * (map_height + 1));
	if (!map_line)
		ft_eror_management("Memory allocation failed", map);
	i = 0;
	while (i < map_height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error_management("Could not read line", map);
		map_line[i] = ft_substr(line, 0, ft_stlen(line));
		if ((i == map_height - 1) && (line[ft_strlen(line) - 1] == '\n'))
			ft_error_management("Map ending wrong", map);
		free(line);
		i++;
	}
	map->map_ber = map_line;
}

void	ft_map_init(t_game *game)
{
	int	fd;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		ft_eror_management("Could not open file", game);
	ft_height(game->map);
	ft_map_ber(game->map, fd, game->map->map_height);
	close(fd);
}
