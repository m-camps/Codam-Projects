/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 17:13:52 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 18:03:23 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_img(t_mlx_data *mlx, t_map_data *map)
{
	mlx->new_img = mlx_new_image(mlx->ptr, map->res_x, map->res_y);
	if (!mlx->new_img)
		on_error(3);
	mlx->addr = mlx_get_data_addr(mlx->new_img, &mlx->bpp, &mlx->ls, &mlx->end);
}

void	replace_img(t_mlx_data *mlx)
{
	mlx->old_img = mlx->new_img;
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->old_img, 0, 0);
}

void	hook(t_move_data *move, t_calc *calc, t_map_data *map)
{
	if (move->forward)
		move_forward(calc, map, move);
	if (move->backward)
		move_backward(calc, map, move);
	if (move->left)
		move_left(calc, map, move);
	if (move->right)
		move_right(calc, map, move);
	if (move->rot_l)
		rotate_left(calc);
	if (move->rot_r)
		rotate_right(calc);
}

void	render(t_mlx_data *mlx, t_move_data *move)
{
	if (move->forward)
		mlx->render = 1;
	if (move->backward)
		mlx->render = 1;
	if (move->left)
		mlx->render = 1;
	if (move->right)
		mlx->render = 1;
	if (move->rot_l)
		mlx->render = 1;
	if (move->rot_r)
		mlx->render = 1;
}

int		image(t_meta_data *meta)
{
	render(&meta->mlx, &meta->move);
	if (meta->mlx.render == 0)
		return (0);
	hook(&meta->move, &meta->calc, &meta->map);
	if (meta->mlx.new_img)
		replace_img(&meta->mlx);
	new_img(&meta->mlx, &meta->map);
	while (meta->calc.x < meta->map.res_x)
	{
		image_calc(meta);
		meta->calc.x++;
	}
	if (meta->spr.amount > 0)
		draw_sprite(meta);
	if (meta->map.screenshot == 1)
		screenshot(meta);
	mlx_put_image_to_window(meta->mlx.ptr, meta->mlx.wdw\
	, meta->mlx.new_img, 0, 0);
	if (meta->mlx.old_img)
		mlx_destroy_image(meta->mlx.ptr, meta->mlx.old_img);
	meta->mlx.render = 0;
	meta->calc.x = 0;
	return (0);
}
