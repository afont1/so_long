#include "so_long_b.h"

void	move_enemies(t_data *data)
{
	t_pos	last_enemies_pos;
    t_pos	next_enemies_pos;

	last_enemies_pos.x = data->map.enemies_pos.x;
	last_enemies_pos.y = data->map.enemies_pos.y;
	next_enemies_pos = chose_direction(data);
	if (last_enemies_pos.x == data->map.exit_pos.x && last_enemies_pos.y == data->map.exit_pos.y)
		data->map.map_split[last_enemies_pos.x][last_enemies_pos.y] = 'E';
	else if (data->map.map_split[last_enemies_pos.x][last_enemies_pos.y] == 'V')
		data->map.map_split[last_enemies_pos.x][last_enemies_pos.y] = 'C';
	else
		data->map.map_split[last_enemies_pos.x][last_enemies_pos.y] = '0';
	if (data->map.map_split[next_enemies_pos.x][next_enemies_pos.y] == 'C')
		data->map.map_split[next_enemies_pos.x][next_enemies_pos.y] = 'V';
	else if (data->map.map_split[next_enemies_pos.x][next_enemies_pos.y] == 'P')
		lose(data);
	else
		data->map.map_split[next_enemies_pos.x][next_enemies_pos.y] = 'X';
	data->map.enemies_pos.x = next_enemies_pos.x;
	data->map.enemies_pos.y = next_enemies_pos.y;
}

t_pos	chose_direction(t_data *data)
{
	int		x_move;
	int		y_move;
	float	dist;
	t_pos	next_enemies_pos;

	x_move = 0;
	y_move = 0;
	dist = 0;
	if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x) * (data->map.player_pos.x - data->map.enemies_pos.x) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1)) && data->map.map_split[data->map.enemies_pos.x][data->map.enemies_pos.y + 1] != '1')
	{
		x_move = 0;
		y_move = 1;
		dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x) * (data->map.player_pos.x - data->map.enemies_pos.x) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1));
	}
	
	if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y) * (data->map.player_pos.y - data->map.enemies_pos.y)) && data->map.map_split[data->map.enemies_pos.x - 1][data->map.enemies_pos.y] != '1')
	{
		x_move = -1;
		y_move = 0;	
		dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y) * (data->map.player_pos.y - data->map.enemies_pos.y));
	}
	
	if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x) * (data->map.player_pos.x - data->map.enemies_pos.x) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1)) && data->map.map_split[data->map.enemies_pos.x][data->map.enemies_pos.y - 1] != '1')
	{
		x_move = 0;
		y_move = -1;	
		dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x) * (data->map.player_pos.x - data->map.enemies_pos.x) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1));
	}
	if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y) * (data->map.player_pos.y - data->map.enemies_pos.y)) && data->map.map_split[data->map.enemies_pos.x + 1][data->map.enemies_pos.y] != '1')
	{
		x_move = 1;
		y_move = 0;	
		dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y) * (data->map.player_pos.y - data->map.enemies_pos.y));
	}
	//if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1)) && data->map.map_split[data->map.enemies_pos.x + 1][data->map.enemies_pos.y - 1] != '1')
	//{
	//	x_move = 1;
	//	y_move = -1;
	//	dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1));
	//}
	//if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1)) && data->map.map_split[data->map.enemies_pos.x + 1][data->map.enemies_pos.y + 1] != '1')
	//{
	//	x_move = 1;
	//	y_move = 1;
	//	dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x + 1) * (data->map.player_pos.x - data->map.enemies_pos.x + 1) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1));
	//}
	//if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1)) && data->map.map_split[data->map.enemies_pos.x - 1][data->map.enemies_pos.y + 1] != '1')
	//{
	//	x_move = -1;
	//	y_move = 1;	
	//	dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y + 1) * (data->map.player_pos.y - data->map.enemies_pos.y + 1));
	//}
	//if (dist < sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1)) && data->map.map_split[data->map.enemies_pos.x - 1][data->map.enemies_pos.y - 1] != '1')
	//{
	//	x_move = -1;
	//	y_move = -1;	
	//	dist = sqrt((data->map.player_pos.x - data->map.enemies_pos.x - 1) * (data->map.player_pos.x - data->map.enemies_pos.x - 1) + (data->map.player_pos.y - data->map.enemies_pos.y - 1) * (data->map.player_pos.y - data->map.enemies_pos.y - 1));
	//}
	next_enemies_pos.x = x_move + data->map.enemies_pos.x;
	next_enemies_pos.y = y_move + data->map.enemies_pos.y;
	return (next_enemies_pos);
}

void	lose(t_data *data)
{
	ft_printf("You lose\n");
	close_window(data);
	exit(EXIT_FAILURE);
}
