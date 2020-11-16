/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_init_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 16:40:10 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/09 18:05:19 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx_data		init_mlx(void)
{
	t_mlx_data	mlx;

	mlx.ptr = 0;
	mlx.wdw = 0;
	mlx.new_img = 0;
	mlx.old_img = 0;
	mlx.addr = 0;
	mlx.bpp = 0;
	mlx.ls = 0;
	mlx.end = 0;
	mlx.render = 1;
	return (mlx);
}

t_move_data		init_move(void)
{
	t_move_data	move;

	move.forward = 0;
	move.backward = 0;
	move.left = 0;
	move.right = 0;
	move.rot_l = 0;
	move.rot_r = 0;
	return (move);
}

t_spr			init_spr(void)
{
	t_spr	spr;

	spr.sprite = 0;
	spr.amount = 0;
	spr.distance = 0;
	spr.sprite_x = 0;
	spr.sprite_y = 0;
	spr.inv = 0;
	spr.transform_x = 0;
	spr.transform_y = 0;
	spr.screen_x = 0;
	spr.height = 0;
	spr.start_y = 0;
	spr.end_y = 0;
	spr.start_x = 0;
	spr.end_x = 0;
	spr.stripe = 0;
	spr.tex_x = 0;
	spr.tex_y = 0;
	return (spr);
}
