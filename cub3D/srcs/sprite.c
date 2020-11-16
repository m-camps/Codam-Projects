/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 16:53:55 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 20:59:07 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_distance(t_spr *spr, t_calc *calc, int i)
{
	spr->distance[i] = ((calc->pos_x - spr->sprite[i][1]) * (calc->pos_x - \
	spr->sprite[i][1])) + ((calc->pos_y - spr->sprite[i][0]) * \
	(calc->pos_y - spr->sprite[i][0]));
}

void	sort_sprites(t_spr *spr, int i)
{
	double	y_tmp;
	double	x_tmp;
	double	distance_tmp;
	int		amount;

	while (i < (spr->amount - 1))
	{
		amount = 0;
		if (spr->distance[i] < spr->distance[i + 1])
		{
			y_tmp = spr->sprite[i + 1][0];
			x_tmp = spr->sprite[i + 1][1];
			distance_tmp = spr->distance[i + 1];
			spr->distance[i + 1] = spr->distance[i];
			spr->sprite[i + 1][0] = spr->sprite[i][0];
			spr->sprite[i + 1][1] = spr->sprite[i][1];
			spr->distance[i] = distance_tmp;
			spr->sprite[i][0] = y_tmp;
			spr->sprite[i][1] = x_tmp;
			amount++;
		}
		if (amount == 0)
			i++;
	}
}

void	calc_sprite(t_spr *spr, t_calc *calc, t_map_data *map, int i)
{
	spr->sprite_x = spr->sprite[i][1] - calc->pos_x;
	spr->sprite_y = spr->sprite[i][0] - calc->pos_y;
	spr->inv = 1.0 / ((calc->plane_x * calc->dir_y) - \
	(calc->dir_x * calc->plane_y));
	spr->transform_x = spr->inv * ((calc->dir_y * spr->sprite_x)\
	- (calc->dir_x * spr->sprite_y));
	spr->transform_y = spr->inv * ((-calc->plane_y * spr->sprite_x)\
	+ (calc->plane_x * spr->sprite_y));
	spr->screen_x = (int)((map->res_x / 2) * (1 + spr->transform_x\
	/ spr->transform_y));
	spr->height = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->start_y = -spr->height / 2 + map->res_y / 2;
	if (spr->start_y < 0)
		spr->start_y = 0;
	spr->end_y = spr->height / 2 + map->res_y / 2;
	if (spr->end_y >= map->res_y)
		spr->end_y = map->res_y - 1;
	spr->width = abs((int)(1 * (map->res_y / spr->transform_y)));
	spr->start_x = -spr->width / 2 + spr->screen_x;
	if (spr->start_x < 0)
		spr->start_x = 0;
	spr->end_x = spr->width / 2 + spr->screen_x;
	if (spr->end_x >= map->res_x)
		spr->end_x = map->res_x - 1;
}

void	draw_sprite(t_meta_data *meta)
{
	int i;

	i = 0;
	while (i < meta->spr.amount)
	{
		calc_distance(&meta->spr, &meta->calc, i);
		i++;
	}
	sort_sprites(&meta->spr, 0);
	i = 0;
	while (i < meta->spr.amount)
	{
		calc_sprite(&meta->spr, &meta->calc, &meta->map, i);
		create_sprite(meta, &meta->spr);
		i++;
	}
}
