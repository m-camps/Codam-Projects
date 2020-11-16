/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 19:06:35 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/12 18:12:32 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	step_direction(t_calc *calc)
{
	if (calc->ray_x < 0)
	{
		calc->step_x = -1;
		calc->dist_x = (calc->pos_x - calc->map_x) * calc->delta_x;
	}
	else
	{
		calc->step_x = 1;
		calc->dist_x = (calc->map_x + 1.0 - calc->pos_x) * calc->delta_x;
	}
	if (calc->ray_y < 0)
	{
		calc->step_y = -1;
		calc->dist_y = (calc->pos_y - calc->map_y) * calc->delta_y;
	}
	else
	{
		calc->step_y = 1;
		calc->dist_y = (calc->map_y + 1.0 - calc->pos_y) * calc->delta_y;
	}
}

void	step(t_calc *calc, t_map_data *map)
{
	if (map->map[calc->map_y][calc->map_x] == 1)
		calc->hit = 1;
	if (calc->dist_x < calc->dist_y)
	{
		calc->dist_x = calc->dist_x + calc->delta_x;
		calc->map_x += calc->step_x;
		calc->side = 0;
	}
	else
	{
		calc->dist_y = calc->dist_y + calc->delta_y;
		calc->map_y += calc->step_y;
		calc->side = 1;
	}
	if (map->map[calc->map_y][calc->map_x] == 1)
		calc->hit = 1;
}

void	side_selection(t_calc *calc)
{
	if (calc->side == 0)
	{
		calc->dist_wall[calc->x] = (calc->map_x - calc->pos_x + \
		(1.0 - calc->step_x) / 2) / calc->ray_x;
		calc->wall_x = calc->pos_y + calc->dist_wall[calc->x] * calc->ray_y;
		if (calc->ray_x > 0)
			calc->wall_or = 'E';
		else
			calc->wall_or = 'W';
	}
	else
	{
		calc->dist_wall[calc->x] = (calc->map_y - calc->pos_y + \
		(1.0 - calc->step_y) / 2) / calc->ray_y;
		calc->wall_x = calc->pos_x + calc->dist_wall[calc->x] * calc->ray_x;
		if (calc->ray_y > 0)
			calc->wall_or = 'S';
		else
			calc->wall_or = 'N';
	}
	calc->wall_x = calc->wall_x - floor(calc->wall_x);
}

void	dda(t_map_data *map, t_calc *calc)
{
	calc->cam_x = 2 * calc->x / (double)map->res_x - 1;
	calc->ray_x = calc->dir_x + (calc->plane_x * calc->cam_x);
	calc->ray_y = calc->dir_y + (calc->plane_y * calc->cam_x);
	calc->delta_x = fabs(1 / calc->ray_x);
	calc->delta_y = fabs(1 / calc->ray_y);
	calc->map_x = (int)calc->pos_x;
	calc->map_y = (int)calc->pos_y;
	step_direction(calc);
	calc->hit = 0;
	while (!calc->hit)
		step(calc, map);
	side_selection(calc);
}
