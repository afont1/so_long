/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:53:04 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:53:06 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	destroy_image(data);
	free_map(data->map.map_split);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(EXIT_FAILURE);
}

void	destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprites.player.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->sprites.item.img_ptr);
}
