/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:05:28 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/09 17:44:22 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	init_spr_w(t_tex *tex)
{
	tex->tex_w = 0;
	tex->addr_w = 0;
	tex->bpp_w = 0;
	tex->ls_w = 0;
	tex->end_w = 0;
	tex->x_w = 0;
	tex->y_w = 0;
	tex->tex_spr = 0;
	tex->addr_spr = 0;
	tex->bpp_spr = 0;
	tex->ls_spr = 0;
	tex->end_spr = 0;
	tex->x_spr = 0;
	tex->y_spr = 0;
	return (*tex);
}

t_tex	init_tex(void)
{
	t_tex	tex;

	tex.tex_n = 0;
	tex.addr_n = 0;
	tex.bpp_n = 0;
	tex.ls_n = 0;
	tex.end_n = 0;
	tex.x_n = 0;
	tex.y_n = 0;
	tex.tex_s = 0;
	tex.addr_s = 0;
	tex.bpp_s = 0;
	tex.ls_s = 0;
	tex.end_s = 0;
	tex.x_s = 0;
	tex.y_s = 0;
	tex.tex_e = 0;
	tex.addr_e = 0;
	tex.bpp_e = 0;
	tex.ls_e = 0;
	tex.end_e = 0;
	tex.x_e = 0;
	tex.y_e = 0;
	tex = init_spr_w(&tex);
	return (tex);
}
