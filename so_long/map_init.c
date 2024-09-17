/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/17 15:18:57 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	lentot;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	lentot = ft_strlen(s + start);
	if (lentot < len)
		len = lentot;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		a[i] = s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
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
