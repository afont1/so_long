/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:52:20 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:52:27 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_init_map(char *gnl_map, t_data *data)
{
	char	**temp;

	temp = check_empty_line(gnl_map, data);
	init_map_data(data->map.map_split, data);
	check_map_data(data->map.map_split, data);
	check_map_path(temp, data);
}

char	**check_empty_line(char *gnl_map, t_data *data)
{
	int		i;
	char	**temp;

	i = -1;
	if (gnl_map[0] == '\n')
		error_empty(gnl_map, "empty line at begining", data);
	while (gnl_map[++i + 1])
		if (gnl_map[i] == '\n' && gnl_map[i + 1] == '\n')
			error_empty(gnl_map, "empty line", data);
	if (gnl_map[ft_strlen(gnl_map) - 1] == '\n')
		error_empty(gnl_map, "empty line at the end", data);
	data->map.map_split = ft_split(gnl_map, '\n');
	temp = ft_split(gnl_map, '\n');
	free(gnl_map);
	return (temp);
}

void	error_empty(char *gnl_map, char *message, t_data *data)
{
	free(gnl_map);
	ft_error(data, message);
}

void	check_map_data(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i + 1 < data->map.row)
	{
		if (ft_strlen_var(map[i]) != ft_strlen_var(map[i + 1]))
			ft_error(data, "not rectangle");
	}
	while (++j < data->map.column)
	{
		if (map[0][j] != '1' || map[data->map.row - 1][j] != '1')
			ft_error(data, "not surrounded by wall");
	}
	i = -1;
	while (++i < data->map.row)
	{
		if (map[i][0] != '1' || map [i][data->map.column - 1] != '1')
			ft_error(data, "not surrounded by wall");
	}
	if (data->map.exit != 1 || data->map.item == 0 || data->map.player != 1)
		ft_error(data, "missing or too much exit, item, player");
}
