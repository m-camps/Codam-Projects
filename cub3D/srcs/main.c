/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 12:52:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/08 19:16:44 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(t_meta_data *meta)
{
	if (meta->map.screenshot == 0)
	{
		ft_putstr("Spawning... \n");
		meta->mlx.wdw = mlx_new_window(meta->mlx.ptr, \
		meta->map.res_x, meta->map.res_y, "cub3D");
		if (!meta->mlx.wdw)
			on_error(3);
		mlx_hook(meta->mlx.wdw, 17, 0, &exit_hook, NULL);
		mlx_hook(meta->mlx.wdw, 2, 0, &keypress_hook, meta);
		mlx_hook(meta->mlx.wdw, 3, 0, &keyrelease_hook, meta);
	}
	mlx_loop_hook(meta->mlx.ptr, &image, meta);
	mlx_loop(meta->mlx.ptr);
}

int		main(int ac, char **av)
{
	t_meta_data		meta;

	meta = init_meta_data();
	argument_check(ac, av, &meta.map);
	read_data(&meta.map, av[1]);
	meta.mlx.ptr = mlx_init();
	if (!meta.mlx.ptr)
		on_error(3);
	fill_spawn(&meta);
	fill_tex(&meta.tex, &meta.mlx, &meta.map);
	fill_spr(&meta.spr, &meta.map);
	game_loop(&meta);
	return (0);
}
