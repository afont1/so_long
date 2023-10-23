/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:52:33 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:52:35 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

void	check_map_path(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	map[data->map.player_pos.x][data->map.player_pos.y] = ' ';
	while (!is_everything_surrounded(map))
	{
		i = -1;
		while (map[++i])
		{
			j = -1;
			while (map[i][++j])
				if (map[i][j] == ' ')
					replaceby_space(map, i, j);
		}
	}
	is_exit_item(map, data);
}

int	is_everything_surrounded(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == ' ' && !is_surrounded(map, i, j))
				return (0);
	}
	return (1);
}

int	is_surrounded(char **map, int x, int y)
{
	if (map[x][y - 1] == 'E' || map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x][y - 1] == 'X')
		return (0);
	if (map[x][y + 1] == 'E' || map[x][y + 1] == '0' || map[x][y + 1] == 'C' || map[x][y + 1] == 'X')
		return (0);
	if (map[x - 1][y] == 'E' || map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x - 1][y] == 'X')
		return (0);
	if (map[x + 1][y] == 'E' || map[x + 1][y] == '0' || map[x + 1][y] == 'C' || map[x + 1][y] == 'X')
		return (0);
	return (1);
}

void	replaceby_space(char **map, int x, int y)
{
	if (map[x][y - 1] == 'E' || map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x][y - 1] == 'X')
		map[x][y - 1] = ' ';
	if (map[x][y + 1] == 'E' || map[x][y + 1] == '0' || map[x][y + 1] == 'C' || map[x][y + 1] == 'X')
		map[x][y + 1] = ' ';
	if (map[x - 1][y] == 'E' || map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x - 1][y] == 'X')
		map[x - 1][y] = ' ';
	if (map[x + 1][y] == 'E' || map[x + 1][y] == '0' || map[x + 1][y] == 'C' || map[x + 1][y] == 'X')
		map[x + 1][y] = ' ';
}

void	is_exit_item(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C' || map[i][j] == 'E')
				ft_error(data, "map can not be finish");
	}
	free_map(map);
}
