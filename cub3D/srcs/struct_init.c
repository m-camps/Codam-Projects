/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 16:40:10 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/09 17:53:46 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_data		init_map_data(void)
{
	t_map_data	map;

	map.index = 0;
	map.res_x = 0;
	map.res_y = 0;
	map.n_path = 0;
	map.s_path = 0;
	map.e_path = 0;
	map.w_path = 0;
	map.spr_path = 0;
	map.floor = 0;
	map.ceiling = 0;
	map.map_x = 0;
	map.map_y = 0;
	map.map = 0;
	map.spawn_loc_x = 0;
	map.spawn_loc_y = 0;
	map.sp_or = '0';
	map.flood = 0;
	map.screenshot = 0;
	return (map);
}

t_calc			init_calc_2(t_calc *calc)
{
	calc->side = 0;
	calc->x = 0;
	calc->wall_or = 0;
	calc->tex_x = 0;
	calc->tex_y = 0;
	calc->step = 0;
	calc->tex_pos = 0;
	return (*calc);
}

t_calc			init_calc(void)
{
	t_calc	calc;

	calc.pos_x = 0;
	calc.pos_y = 0;
	calc.dir_x = 0;
	calc.dir_y = 0;
	calc.plane_x = 0;
	calc.plane_y = 0;
	calc.cam_x = 0;
	calc.ray_x = 0;
	calc.ray_y = 0;
	calc.dist_x = 0;
	calc.dist_y = 0;
	calc.delta_x = 0;
	calc.delta_y = 0;
	calc.dist_wall = 0;
	calc.wall_x = 0;
	calc.map_x = 0;
	calc.map_y = 0;
	calc.step_x = 0;
	calc.step_y = 0;
	calc.hit = 0;
	calc = init_calc_2(&calc);
	return (calc);
}

t_meta_data		init_meta_data(void)
{
	t_meta_data	meta;

	meta.map = init_map_data();
	meta.mlx = init_mlx();
	meta.move = init_move();
	meta.calc = init_calc();
	meta.tex = init_tex();
	meta.spr = init_spr();
	return (meta);
}
