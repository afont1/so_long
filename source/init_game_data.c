/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:53:15 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:53:16 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error(data, "can not init mlx");
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
data->map.column * 64, data->map.row * 64, "so_long");
	if (data->win_ptr == NULL)
		ft_error(data, "can not init the new window");
}

void	init_img(t_data *data)
{
	data->sprites.exit.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
"sprites/exit.xpm", &data->sprites.exit.x, &data->sprites.exit.y);
	data->sprites.floor.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
"sprites/floor.xpm", &data->sprites.floor.x, &data->sprites.floor.y);
	data->sprites.item.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
"sprites/item.xpm", &data->sprites.item.x, &data->sprites.item.y);
	data->sprites.player.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
"sprites/player.xpm", &data->sprites.player.x, &data->sprites.player.y);
	data->sprites.wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
"sprites/wall.xpm", &data->sprites.wall.x, &data->sprites.wall.y);
	if (data->sprites.exit.img_ptr == NULL)
		ft_error(data, "missing exit.xpm file");
	if (data->sprites.floor.img_ptr == NULL)
		ft_error(data, "missing floor.xpm file");
	if (data->sprites.item.img_ptr == NULL)
		ft_error(data, "missing item.xpm file");
	if (data->sprites.player.img_ptr == NULL)
		ft_error(data, "missing player.xpm file");
	if (data->sprites.wall.img_ptr == NULL)
		ft_error(data, "missing wall.xpm file");
}
