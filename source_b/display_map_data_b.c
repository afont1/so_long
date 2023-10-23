/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:52:43 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:52:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

int	display_map_data(t_data *data)
{
	int		x;
	int		y;
	char	*temp;

	x = -1;
	while (++x < data->map.row)
	{
		y = -1;
		while (++y < data->map.column)
			display_img(data, data->map.map_split[x][y], x, y);
	}
	temp = ft_itoa(data->movement);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, 40, 1999, temp);
	free(temp);
	return (0);
}

void	display_img(t_data *data, int c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.wall.img_ptr, y * data->sprites.wall.x, x * data->sprites.wall.y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.floor.img_ptr, y * data->sprites.floor.x, x * \
data->sprites.floor.y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.player.img_ptr, y * data->sprites.player.x, x * \
data->sprites.player.y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.item.img_ptr, y * data->sprites.item.x, x * data->sprites.item.y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.exit.img_ptr, y * data->sprites.exit.x, x * data->sprites.exit.y);
	else if (c == 'X' || c == 'V')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
data->sprites.enemies.img_ptr, y * data->sprites.enemies.x, x * data->sprites.enemies.y);
}
