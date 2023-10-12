/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:55:35 by afont             #+#    #+#             */
/*   Updated: 2023/08/27 13:55:37 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "ft_printf/include/ft_printf.h"
#include "GNL/get_next_line.h"

typedef struct s_pos		t_pos;
struct s_pos
{
	int	x;
	int	y;
};

typedef struct s_img_data	t_img_data;
struct s_img_data
{
	void	*img_ptr;
	int		x;
	int		y;
};

typedef struct s_img		t_img;
struct s_img
{
	t_img_data	wall;
	t_img_data	floor;
	t_img_data	player;
	t_img_data	item;
	t_img_data	exit;
};

typedef struct s_map		t_map;
struct s_map
{
	char		**map_split;
	int			row;
	int			column;
	int			item;
	int			exit;
	int			player;
	t_pos		exit_pos;
	t_pos		player_pos;
};

typedef struct s_data		t_data;
struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movement;
	t_map		map;
	t_img		sprites;
};

char	*ft_get_map(t_data *data, char *argv);
void	check_init_map(char *gnl_map, t_data *data);
void	init_map_data(char **map, t_data *data);
char	**check_empty_line(char *gnl_map, t_data *data);
void	ft_error(t_data *data, char *message);
void	check_map_data(char **map, t_data *data);
void	check_arg(t_data *data, int argc, char **argv);
void	ft_value_zero(t_data *data);
void	free_map(char **str);
int		ft_strlen_var(char *s);
void	init_window(t_data *data);
void	init_img(t_data *data);
int		keyhandler(int Key, t_data *data);
void	move_player(t_data *data, int x, int y);
int		display_map_data(t_data *data);
void	display_img(t_data *data, int c, int x, int y);
void	destroy_image(t_data *data);
int		close_window(t_data *data);
void	win(t_data *data);
void	check_map_path(char **map, t_data *data);
int		is_everything_surrounded(char **map);
int		is_surrounded(char **map, int x, int y);
void	replaceby_space(char **map, int x, int y);
void	is_exit_item(char **map, t_data *data);
char	*ft_free_join(char *s1, char *s2);
void	error_empty(char *gnl_map, char *message, t_data *data);
void	init_map_data_2(char **map, t_data *data, int i, int j);
