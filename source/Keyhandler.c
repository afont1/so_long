/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:53:31 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:53:33 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhandler(int Key, t_data *data)
{
	if (Key == 65362 || Key == 119)
		move_player(data, data->map.player_pos.x - 1, data->map.player_pos.y);
	if (Key == 65361 || Key == 97)
		move_player(data, data->map.player_pos.x, data->map.player_pos.y - 1);
	if (Key == 65363 || Key == 100)
		move_player(data, data->map.player_pos.x, data->map.player_pos.y + 1);
	if (Key == 65364 || Key == 115)
		move_player(data, data->map.player_pos.x + 1, data->map.player_pos.y);
	if (Key == 65307 || Key == 113)
		close_window(data);
	return (0);
}

void	move_player(t_data *data, int x, int y)
{
	t_pos			last_player_pos;

	last_player_pos.x = data->map.player_pos.x;
	last_player_pos.y = data->map.player_pos.y;
	if (data->map.map_split[x][y] == 'E' && data->map.item == 0)
		win(data);
	else if (data->map.map_split[x][y] != '1')
	{
		if (data->map.map_split[x][y] == 'C')
			data->map.item--;
		data->map.map_split[data->map.exit_pos.x][data->map.exit_pos.y] = 'E';
		data->map.map_split[x][y] = 'P';
		if (last_player_pos.x == data->map.exit_pos.x && \
last_player_pos.y == data->map.exit_pos.y)
			data->map.map_split[last_player_pos.x][last_player_pos.y] = 'E';
		else
			data->map.map_split[last_player_pos.x][last_player_pos.y] = '0';
		data->map.player_pos.x = x;
		data->map.player_pos.y = y;
		data->movement++;
		ft_printf("%d Mouvements\n", data->movement);
		display_map_data(data);
	}
}

void	win(t_data *data)
{
	ft_printf("You win\n");
	close_window(data);
	exit(EXIT_FAILURE);
}
