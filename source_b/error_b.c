/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:52:56 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:52:58 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

void	ft_error(t_data *data, char *message)
{
	if (data->map.map_split)
		free_map(data->map.map_split);
	free(data);
	ft_printf("Error (%s)\n", message);
	exit(EXIT_FAILURE);
}

void	free_map(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_value_zero(t_data *data)
{
	data->map.column = 0;
	data->map.exit = 0;
	data->map.item = 0;
	data->map.player = 0;
	data->map.row = 0;
	data->map.player_pos.x = 0;
	data->map.player_pos.y = 0;
	data->map.enemies_pos.x = 0;
	data->map.enemies_pos.y = 0;
	data->movement = 0;
	data->map.map_split = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

int	ft_strlen_var(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
