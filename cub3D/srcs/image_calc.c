/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 13:11:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/12 19:00:34 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	line_position(t_map_data *map, t_calc *calc)
{
	calc->wall_height = map->res_y;
	calc->line_height = ((int)(calc->wall_height / \
	calc->dist_wall[calc->x]));
	calc->draw_start = -(calc->line_height / 2) + (calc->wall_height / 2);
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = (calc->line_height / 2) + (calc->wall_height / 2);
	if (calc->draw_end >= calc->wall_height)
		calc->draw_end = calc->wall_height - 1;
}

int		get_texture(t_calc *calc, t_tex *tex, int or)
{
	int pixel;

	calc->tex_y = (int)calc->tex_pos;
	calc->tex_pos = calc->tex_pos + calc->step;
	if (or == 'N')
	{
		pixel = *(int*)(tex->addr_n + (calc->tex_y * \
		tex->ls_n + calc->tex_x * (tex->bpp_n / 8)));
	}
	else if (or == 'S')
	{
		pixel = *(int*)(tex->addr_s + (calc->tex_y * \
		tex->ls_s + calc->tex_x * (tex->bpp_s / 8)));
	}
	else if (or == 'W')
	{
		pixel = *(int*)(tex->addr_w + (calc->tex_y * \
		tex->ls_w + calc->tex_x * (tex->bpp_w / 8)));
	}
	else
	{
		pixel = *(int*)(tex->addr_e + (calc->tex_y * \
		tex->ls_e + calc->tex_x * (tex->bpp_e / 8)));
	}
	return (pixel);
}

void	draw_line(t_mlx_data *mlx, t_calc *calc, t_map_data *map, t_tex *tex)
{
	int		y;
	int		pixel;

	y = 0;
	while (y < calc->draw_start)
	{
		*(int*)(mlx->addr + (y * mlx->ls) + \
		(calc->x * (mlx->bpp / 8))) = map->ceiling;
		y++;
	}
	while (calc->draw_start < calc->draw_end)
	{
		pixel = get_texture(calc, tex, calc->wall_or);
		pixel < 0 ? pixel = 0 : pixel;
		*(int*)(mlx->addr + (calc->draw_start * mlx->ls) \
		+ (calc->x * (mlx->bpp / 8))) = pixel;
		calc->draw_start++;
	}
	y = calc->draw_end;
	while (y < map->res_y)
	{
		*(int*)(mlx->addr + (y * mlx->ls) + \
		(calc->x * (mlx->bpp / 8))) = map->floor;
		y++;
	}
}

void	calc_tex(t_tex *tex, t_calc *calc)
{
	if (calc->wall_or == 'N')
	{
		calc->tex_x = (int)(calc->wall_x * (double)tex->x_n);
		calc->step = 1.0 * tex->y_n / calc->line_height;
	}
	else if (calc->wall_or == 'S')
	{
		calc->tex_x = (int)(calc->wall_x * (double)tex->x_s);
		calc->step = 1.0 * tex->y_s / calc->line_height;
	}
	else if (calc->wall_or == 'W')
	{
		calc->tex_x = (int)(calc->wall_x * (double)tex->x_w);
		calc->step = 1.0 * tex->y_w / calc->line_height;
	}
	else if (calc->wall_or == 'E')
	{
		calc->tex_x = (int)(calc->wall_x * (double)tex->x_e);
		calc->step = 1.0 * tex->y_e / calc->line_height;
	}
	calc->tex_pos = (calc->draw_start - (calc->wall_height / 2) \
	+ (calc->line_height / 2)) * calc->step;
}

void	image_calc(t_meta_data *meta)
{
	dda(&meta->map, &meta->calc);
	line_position(&meta->map, &meta->calc);
	calc_tex(&meta->tex, &meta->calc);
	draw_line(&meta->mlx, &meta->calc, &meta->map, &meta->tex);
}
