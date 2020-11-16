/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_tex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:18:27 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/09 17:36:45 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_tex_side(t_tex *t, t_mlx_data *mlx, t_map_data *m)
{
	if (m->n_path[ft_strlen(m->n_path) - 1] == 'm')
		t->tex_n = mlx_xpm_file_to_image(mlx->ptr, m->n_path, &t->x_n, &t->y_n);
	else
		t->tex_n = mlx_png_file_to_image(mlx->ptr, m->n_path, &t->x_n, &t->y_n);
	if (m->s_path[ft_strlen(m->s_path) - 1] == 'm')
		t->tex_s = mlx_xpm_file_to_image(mlx->ptr, m->s_path, &t->x_s, &t->y_s);
	else
		t->tex_s = mlx_png_file_to_image(mlx->ptr, m->s_path, &t->x_s, &t->y_s);
	if (m->e_path[ft_strlen(m->e_path) - 1] == 'm')
		t->tex_e = mlx_xpm_file_to_image(mlx->ptr, m->e_path, &t->x_e, &t->y_e);
	else
		t->tex_e = mlx_png_file_to_image(mlx->ptr, m->e_path, &t->x_e, &t->y_e);
	if (m->w_path[ft_strlen(m->w_path) - 1] == 'm')
		t->tex_w = mlx_xpm_file_to_image(mlx->ptr, m->w_path, &t->x_w, &t->y_w);
	else
		t->tex_w = mlx_png_file_to_image(mlx->ptr, m->w_path, &t->x_w, &t->y_w);
	free(m->n_path);
	free(m->s_path);
	free(m->e_path);
	free(m->w_path);
	if (!t->tex_n || !t->tex_s || !t->tex_e || !t->tex_w)
		on_error(10);
}

void	fill_tex_sprite(t_tex *tex, t_mlx_data *mlx, t_map_data *map)
{
	if (map->spr_path[ft_strlen(map->spr_path) - 1] == 'm')
		tex->tex_spr = mlx_xpm_file_to_image(mlx->ptr, map->spr_path\
		, &tex->x_spr, &tex->y_spr);
	else
		tex->tex_spr = mlx_png_file_to_image(mlx->ptr, map->spr_path\
		, &tex->x_spr, &tex->y_spr);
	if (!tex->tex_spr)
		on_error(10);
	free(map->spr_path);
}

void	fill_tex(t_tex *t, t_mlx_data *mlx, t_map_data *m)
{
	fill_tex_side(t, mlx, m);
	fill_tex_sprite(t, mlx, m);
	t->addr_n = mlx_get_data_addr(t->tex_n, &t->bpp_n, &t->ls_n, &t->end_n);
	t->addr_s = mlx_get_data_addr(t->tex_s, &t->bpp_s, &t->ls_s, &t->end_s);
	t->addr_w = mlx_get_data_addr(t->tex_w, &t->bpp_w, &t->ls_w, &t->end_w);
	t->addr_e = mlx_get_data_addr(t->tex_e, &t->bpp_e, &t->ls_e, &t->end_e);
	t->addr_spr = mlx_get_data_addr(t->tex_spr, &t->bpp_spr\
	, &t->ls_spr, &t->end_spr);
}
