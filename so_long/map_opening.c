/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_opening.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:25:22 by ricmanue          #+#    #+#             */
/*   Updated: 2025/02/17 10:28:53 by ricmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_map_height(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : opening file\n");
		exit(1);
	}
	game->map->map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		game->map->map_height++;
	}
	game->map->map_height--;
	close(fd);
}

static void	ft_map_ber(t_game *game, int fd)
{
	int		i;
	char	*line;
	char	**map;

	map = malloc(sizeof(char *) * (game->map->map_height + 2));
	if (!map)
	{
		ft_printf("Errror : malloc of map failed");
		exit(1);
	}
	i = 0;
	while (i <= game->map->map_height)
	{
		line = get_next_line(fd);
		map[i] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		i++;
	}
	map[i] = NULL;
	game->map->map_ber = map;
}

void	ft_exit_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= game->map->map_height)
	{
		j = 0;
		while (j <= game->map->map_width)
		{
			if (game->map->map_ber[i][j] == 'E')
			{
				game->map->x_exit = j;
				game->map->y_exit = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_map_creation(t_game *game)
{
	int	fd;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: opening file\n");
		exit(1);
	}
	ft_map_height(game);
	ft_map_ber(game, fd);
	close(fd);
}
