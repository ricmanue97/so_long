/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/24 11:41:44 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_height(t_game *game)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		ft_error_management("Error: could not open file", game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	game->map->map_height = i;
}

void	ft_map_ber(t_game *game, int fd, int map_height)
{
	char	**map_line;
	char	*line;
	int		i;

	map_line = malloc(sizeof(char *) * (game->map->map_height + 1));
	if (!map_line)
		ft_error_management("Error: memory allocation failed", game);
	i = 0;
	while (i < game->map->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error_management("Error: could not read line", game);
		map_line[i] = ft_substr(line, 0, ft_strlen(line));
		if ((i == game->map->map_height - 1) && (line[ft_strlen(line) - 1] == '\n'))
			ft_error_management("Error: map ending wrong", game);
		free(line);
		i++;
	}
	game->map->map_ber = map_line;
}

void	ft_map_init(t_game *game)
{
	int	fd;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		ft_error_management("Error: could not open file", game);
	ft_height(game);
	ft_map_ber(game, fd, game->map->map_height);
	close(fd);
}
