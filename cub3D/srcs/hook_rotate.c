/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 20:16:55 by mcamps        #+#    #+#                 */
/*   Updated: 2020/09/14 20:36:43 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	rotate_left(t_calc *calc)
{
	double	dir_old;
	double	plane_old;

	dir_old = calc->dir_x;
	plane_old = calc->plane_x;
	calc->dir_x = calc->dir_x * cos(-0.04) - calc->dir_y * sin(-0.04);
	calc->dir_y = dir_old * sin(-0.04) + calc->dir_y * cos(-0.04);
	calc->plane_x = calc->plane_x * cos(-0.04) - calc->plane_y * sin(-0.04);
	calc->plane_y = plane_old * sin(-0.04) + calc->plane_y * cos(-0.04);
}

void	rotate_right(t_calc *calc)
{
	double	dir_old;
	double	plane_old;

	dir_old = calc->dir_x;
	plane_old = calc->plane_x;
	calc->dir_x = calc->dir_x * cos(0.04) - calc->dir_y * sin(0.04);
	calc->dir_y = dir_old * sin(0.04) + calc->dir_y * cos(0.04);
	calc->plane_x = calc->plane_x * cos(0.04) - calc->plane_y * sin(0.04);
	calc->plane_y = plane_old * sin(0.04) + calc->plane_y * cos(0.04);
}
