/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/07 18:38:37 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/12 19:22:50 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_flood(t_map_data *map_data, int max_x)
{
	int y;

	y = 0;
	map_data->flood = (int**)malloc(sizeof(int*) * map_data->map_y);
	if (!map_data->flood)
		on_error(9);
	while (y < map_data->map_y)
	{
		map_data->flood[y] = (int*)malloc(sizeof(int) * max_x);
		if (!map_data->flood[y])
			on_error(9);
		y++;
	}
}

void	fill_flood(t_map_data *map_data, int max_x)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_data->map_y)
	{
		x = 0;
		while (x < map_data->map_x[y])
		{
			map_data->flood[y][x] = map_data->map[y][x];
			if (map_data->flood[y][x] == 2)
				map_data->flood[y][x] = 0;
			x++;
		}
		while (x < max_x)
		{
			map_data->flood[y][x] = 9;
			x++;
		}
		y++;
	}
}

void	floodfill(int y, int x, t_map_data *map_data)
{
	if (y == map_data->map_y - 1 || x == (map_data->map_x[y] - 1))
		on_error(1);
	if (map_data->flood[y][x] == 9 || x == 0 || y == 0)
		on_error(1);
	if (map_data->flood[y][x] == 0)
	{
		map_data->flood[y][x] = 7;
		if (map_data->flood[y + 1][x] != 1)
			floodfill(y + 1, x, map_data);
		if (map_data->flood[y + 1][x + 1] != 1)
			floodfill(y + 1, x + 1, map_data);
		if (map_data->flood[y + 1][x - 1] != 1)
			floodfill(y + 1, x - 1, map_data);
		if (map_data->flood[y - 1][x] != 1)
			floodfill(y - 1, x, map_data);
		if (map_data->flood[y - 1][x + 1] != 1)
			floodfill(y - 1, x + 1, map_data);
		if (map_data->flood[y - 1][x - 1] != 1)
			floodfill(y - 1, x - 1, map_data);
		if (map_data->flood[y][x + 1] != 1)
			floodfill(y, x + 1, map_data);
		if (map_data->flood[y][x - 1] != 1)
			floodfill(y, x - 1, map_data);
	}
}

void	free_flood(t_map_data *map_data)
{
	int	y;

	y = 0;
	while (y < map_data->map_y)
	{
		free(map_data->flood[y]);
		y++;
	}
	free(map_data->flood);
}

void	check_map(t_map_data *map_data)
{
	int max_x;
	int y;

	y = 0;
	max_x = 0;
	while (y < map_data->map_y)
	{
		if (map_data->map_x[y] > max_x)
			max_x = map_data->map_x[y];
		y++;
	}
	malloc_flood(map_data, max_x);
	fill_flood(map_data, max_x);
	floodfill(map_data->spawn_loc_y, map_data->spawn_loc_x, map_data);
	free_flood(map_data);
}
