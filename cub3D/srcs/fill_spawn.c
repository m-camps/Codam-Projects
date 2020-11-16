/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_spawn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 20:37:10 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 17:25:31 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_orientation_we(t_calc *calc, t_map_data *map)
{
	if (map->sp_or == 'W')
	{
		calc->dir_x = -1;
		calc->dir_y = 0;
		calc->plane_x = 0;
		calc->plane_y = -0.66;
	}
	else if (map->sp_or == 'E')
	{
		calc->dir_x = 1;
		calc->dir_y = 0;
		calc->plane_x = 0;
		calc->plane_y = 0.66;
	}
}

void	set_orientation(t_calc *calc, t_map_data *map)
{
	if (map->sp_or == 'S')
	{
		calc->dir_x = 0;
		calc->dir_y = 1;
		calc->plane_x = -0.66;
		calc->plane_y = 0;
	}
	else if (map->sp_or == 'N')
	{
		calc->dir_x = 0;
		calc->dir_y = -1;
		calc->plane_x = 0.66;
		calc->plane_y = 0;
	}
	else
		set_orientation_we(calc, map);
}

void	fill_spawn(t_meta_data *meta)
{
	meta->calc.pos_x = (double)meta->map.spawn_loc_x + 0.5;
	meta->calc.pos_y = (double)meta->map.spawn_loc_y + 0.5;
	meta->calc.dist_wall = (double*)malloc(sizeof(double) * meta->map.res_x);
	if (!meta->calc.dist_wall)
		on_error(9);
	set_orientation(&meta->calc, &meta->map);
}
