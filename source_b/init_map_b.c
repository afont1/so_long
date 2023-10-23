/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:53:23 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:53:25 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

void	check_arg(t_data *data, int argc, char **argv)
{
	int	i;

	if (argc == 1)
		ft_error(data, "no argument");
	i = ft_strlen(argv[1]);
	if (argc != 2)
		ft_error(data, "too much arguments");
	if (i < 5)
		ft_error(data, "file name not up to standar");
	if (argv[1][i - 1] != 'r' || \
argv[1][i - 2] != 'e' || \
argv[1][i - 3] != 'b' || \
argv[1][i - 4] != '.')
		ft_error(data, "no .ber at the end of the file name");
}

char	*ft_get_map(t_data *data, char *argv)
{
	int		fd;
	char	*gnl_map;
	char	*gnl;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(data, "can not open file");
	gnl_map = "";
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		gnl_map = ft_free_join(gnl_map, gnl);
	}
	close(fd);
	if (!gnl_map[0])
		ft_error(data, "map empty");
	return (gnl_map);
}

void	init_map_data(char **map, t_data *data)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (map[++i])
	{
		data->map.row++;
		while (map[i][++j])
			init_map_data_2(map, data, i, j);
		j = 0;
	}
	data->map.column = ft_strlen(map[0]);
}

void	init_map_data_2(char **map, t_data *data, int i, int j)
{
	if (map[i][j] == 'C')
		data->map.item++;
	else if (map[i][j] == 'E')
	{
		data->map.exit++;
		data->map.exit_pos.x = i;
		data->map.exit_pos.y = j;
	}
	else if (map[i][j] == 'P')
	{
		data->map.player++;
		data->map.player_pos.x = i;
		data->map.player_pos.y = j;
	}
	else if (map[i][j] == 'X')
	{
		data->map.enemies_pos.x = i;
		data->map.enemies_pos.y = j;
	}
	else if (map[i][j] != '1' && map[i][j] != '0')
		ft_error(data, "character unknow");
}

char	*ft_free_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (s1[0])
		free(s1);
	free(s2);
	return (temp);
}
