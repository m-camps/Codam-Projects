/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 19:31:19 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/02 10:13:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_calc *calc, t_map_data *map, t_move_data *move)
{
	if (move->left || move->right)
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x + (calc->dir_x * 0.1))] == 0)
			calc->pos_x = calc->pos_x + (calc->dir_x * 0.07);
		if (map->map[(int)(calc->pos_y + \
		(calc->dir_y * 0.1))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y + (calc->dir_y * 0.07);
	}
	else
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x + (calc->dir_x * 0.14))] == 0)
			calc->pos_x = calc->pos_x + (calc->dir_x * 0.1);
		if (map->map[(int)(calc->pos_y + \
		(calc->dir_y * 0.14))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y + (calc->dir_y * 0.1);
	}
}

void	move_backward(t_calc *calc, t_map_data *map, t_move_data *move)
{
	if (move->left || move->right)
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x - (calc->dir_x * 0.1))] == 0)
			calc->pos_x = calc->pos_x - (calc->dir_x * 0.07);
		if (map->map[(int)(calc->pos_y - \
		(calc->dir_y * 0.1))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y - (calc->dir_y * 0.07);
	}
	else
	{
		if (map->map[(int)calc->pos_y][(int)(calc->pos_x - \
		(calc->dir_x * 0.14))] == 0)
			calc->pos_x = calc->pos_x - (calc->dir_x * 0.1);
		if (map->map[(int)(calc->pos_y - \
		(calc->dir_y * 0.14))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y - (calc->dir_y * 0.1);
	}
}

void	move_left(t_calc *calc, t_map_data *map, t_move_data *move)
{
	if (move->forward || move->forward)
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x - (calc->plane_x * 0.07))] == 0)
			calc->pos_x = calc->pos_x - (calc->plane_x * 0.05);
		if (map->map[(int)(calc->pos_y - \
		(calc->plane_y * 0.07))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y - (calc->plane_y * 0.05);
	}
	else
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x - (calc->plane_x * 0.14))] == 0)
			calc->pos_x = calc->pos_x - (calc->plane_x * 0.1);
		if (map->map[(int)(calc->pos_y - \
		(calc->plane_y * 0.14))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y - (calc->plane_y * 0.1);
	}
}

void	move_right(t_calc *calc, t_map_data *map, t_move_data *move)
{
	if (move->forward || move->forward)
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x + (calc->plane_x * 0.07))] == 0)
			calc->pos_x = calc->pos_x + (calc->plane_x * 0.05);
		if (map->map[(int)(calc->pos_y + \
		(calc->plane_y * 0.07))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y + (calc->plane_y * 0.05);
	}
	else
	{
		if (map->map[(int)calc->pos_y][(int)\
		(calc->pos_x + (calc->plane_x * 0.14))] == 0)
			calc->pos_x = calc->pos_x + (calc->plane_x * 0.1);
		if (map->map[(int)(calc->pos_y + \
		(calc->plane_y * 0.14))][(int)calc->pos_x] == 0)
			calc->pos_y = calc->pos_y + (calc->plane_y * 0.1);
	}
}
