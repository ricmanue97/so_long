/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:52:23 by ricmanue          #+#    #+#             */
/*   Updated: 2024/09/04 12:09:04 by ricmanue         ###   ########.fr       */
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

	i = 0;
	while (map->map_ber[i])
	{
		map->map_height = i;
		i++;
	}
}
int ft_check_row(char **row, int i)
{

}

int	map_check(t_map *map)
{
	int	i;
	int	count;
	t_map *tmp;

	tmp = map;
	ft_heigt(tmp);
	i=0;
	while (tmp->map_ber[i])
	{
		count = ft_strlen(tmp->map_ber[0]);
		if (count != ft_strlen(tmp->map_ber[i]));
			return(1);
		if(ft_check_row(tmp->map_ber, i) == 1)
			return(1);
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
