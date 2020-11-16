/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_spr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 18:12:31 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/08 18:22:38 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_size(t_spr *spr, t_map_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x[y])
		{
			if (map->map[y][x] == 2)
				spr->amount++;
			x++;
		}
		y++;
	}
}

void	make_sprite_array(t_spr *spr, int size)
{
	int	i;

	i = 0;
	spr->sprite = (double**)malloc(sizeof(double*) * size);
	if (!spr->sprite)
		on_error(9);
	while (i < size)
	{
		spr->sprite[i] = (double*)malloc(sizeof(double) * 2);
		if (!spr->sprite[i])
			on_error(9);
		i++;
	}
	spr->distance = (double*)malloc(sizeof(double) * size);
	if (!spr->distance)
		on_error(9);
}

void	fill_sprite_array(t_spr *spr, t_map_data *map)
{
	int	y;
	int	x;
	int i;

	y = 0;
	i = 0;
	while (y < map->map_y)
	{
		x = 0;
		while (x < map->map_x[y])
		{
			if (map->map[y][x] == 2)
			{
				spr->sprite[i][0] = y + 0.5;
				spr->sprite[i][1] = x + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	fill_spr(t_spr *spr, t_map_data *map)
{
	get_size(spr, map);
	if (spr->amount == 0)
		return ;
	make_sprite_array(spr, spr->amount);
	fill_sprite_array(spr, map);
}
