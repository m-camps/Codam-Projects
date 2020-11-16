/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 17:07:14 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/12 20:28:28 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	check_data(t_map_data *map_data)
{
	ft_putstr("Verifying data \xE2\x9C\x94\n");
	if (map_data->res_x == 0 || map_data->res_y == 0)
		on_error(7);
	if (!map_data->n_path || !map_data->s_path || !map_data->e_path)
		on_error(7);
	if (!map_data->w_path || !map_data->spr_path)
		on_error(7);
	if (map_data->map_x == 0 || map_data->map_y == 0)
		on_error(7);
	if (map_data->spawn_loc_x == 0 || map_data->spawn_loc_y == 0)
		on_error(7);
	if (!map_data->map || map_data->sp_or == 0)
		on_error(7);
	if (map_data->f_check == 0 || map_data->c_check == 0)
		on_error(7);
}

static	void	get_data(t_map_data *map_data, char *map)
{
	if (map[map_data->index] == 'R')
		get_res(map_data, map);
	else if (map[map_data->index] == 'N' && map[map_data->index + 1] == 'O')
		get_path(map_data, map, 'N');
	else if (map[map_data->index] == 'S' && map[map_data->index + 1] == 'O')
		get_path(map_data, map, 'S');
	else if (map[map_data->index] == 'W' && map[map_data->index + 1] == 'E')
		get_path(map_data, map, 'W');
	else if (map[map_data->index] == 'E' && map[map_data->index + 1] == 'A')
		get_path(map_data, map, 'E');
	else if (map[map_data->index] == 'S')
		get_path(map_data, map, 'T');
	else if (map[map_data->index] == 'F')
		get_color(map_data, map, 'F');
	else if (map[map_data->index] == 'C')
		get_color(map_data, map, 'C');
	else if (map[map_data->index] == '1')
		get_map(map_data, map);
	else
		on_error(8);
}

void			parse_data(t_map_data *map_data, char *map)
{
	while (map[map_data->index] != '\0')
	{
		while (map[map_data->index] == ' ')
			map_data->index++;
		get_data(map_data, map);
		while (map[map_data->index] == '\n')
			map_data->index++;
	}
	check_data(map_data);
}
