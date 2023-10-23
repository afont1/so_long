/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:53:42 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:53:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	ft_value_zero(data);
	check_arg(data, argc, argv);
	check_init_map(ft_get_map(data, argv[1]), data);
	init_window(data);
	init_img(data);
	display_map_data(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, keyhandler, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_window, data);
	mlx_hook(data->win_ptr, Expose, ExposureMask, display_map_data, data);
	mlx_loop(data->mlx_ptr);
	close_window(data);
}
