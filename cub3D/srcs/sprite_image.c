/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 17:29:10 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 20:58:52 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_sprite(t_meta_data *m, t_spr *spr, int y)
{
	int	d;
	int	color;

	d = (y * 256) - m->map.res_y * 128 + m->spr.height * 128;
	spr->tex_y = ((d * m->tex.y_spr) / spr->height) / 256;
	if (spr->tex_y < 0)
		spr->tex_y = 0;
	color = *(int*)(m->tex.addr_spr + (spr->tex_y * m->tex.ls_spr \
	+ spr->tex_x * (m->tex.bpp_spr / 8)));
	if (color > 0)
	{
		*(int*)(m->mlx.addr + (y * m->mlx.ls) + \
		(spr->stripe * (m->mlx.bpp / 8))) = color;
	}
}

void	create_sprite(t_meta_data *m, t_spr *spr)
{
	int	y;

	spr->stripe = spr->start_x;
	while (spr->stripe < spr->end_x)
	{
		spr->tex_x = (int)(256 * (spr->stripe - (-spr->width / 2 + \
		spr->screen_x)) * m->tex.x_spr / spr->width) / 256;
		if (spr->tex_x < 0)
			spr->tex_x = 0;
		y = spr->start_y;
		if (spr->transform_y > 0.1 && spr->stripe > 0 && spr->stripe < \
		m->map.res_x && spr->transform_y < m->calc.dist_wall[spr->stripe])
		{
			while (y < spr->end_y)
			{
				draw_pixel_sprite(m, spr, y);
				y++;
			}
		}
		spr->stripe++;
	}
}
