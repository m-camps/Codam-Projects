/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_res.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 17:06:49 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/12 20:29:17 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_max_res(t_map_data *map_data, int x)
{
	int		y;
	void	*ptr;

	y = 0;
	if ((map_data->res_x > 16384 || map_data->res_y > 16384) \
	&& map_data->screenshot == 1)
	{
		ft_putstr("Resolution to high for mlx to handle\n");
		on_error(4);
	}
	if (map_data->screenshot == 1)
		return ;
	ptr = mlx_init();
	mlx_get_screen_size(ptr, &x, &y);
	if (map_data->res_x > x)
	{
		map_data->res_x = x;
		ft_putstr("X resolution to high. Set resolution to max screen size.\n");
	}
	if (map_data->res_y > y)
	{
		map_data->res_y = y;
		ft_putstr("Y resolution to high. Set resolution to max screen size.\n");
	}
}

void	fill_res(t_map_data *map_data, char *res_str, char axis)
{
	int		res;

	res = ft_atoi(res_str, 0);
	free(res_str);
	if (axis == 'x')
		map_data->res_x = res;
	if (axis == 'y')
		map_data->res_y = res;
}

void	extract_res(t_map_data *map_data, char *map, char axis)
{
	int		i;
	char	*res;

	i = map_data->index;
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	res = (char*)malloc(sizeof(char) * ((i - map_data->index) + 1));
	if (!res)
		on_error(9);
	i = 0;
	while (map[map_data->index] >= '0' && map[map_data->index] <= '9')
	{
		res[i] = map[map_data->index];
		i++;
		map_data->index++;
	}
	res[i] = '\0';
	fill_res(map_data, res, axis);
}

void	get_res(t_map_data *map_data, char *map)
{
	map_data->index++;
	map_data->index = skip_empty_space(map_data->index, map);
	if (map[map_data->index] >= '1' || map[map_data->index] <= '9')
		extract_res(map_data, map, 'x');
	else
		on_error(4);
	if (map[map_data->index] != ' ')
		on_error(4);
	while (map[map_data->index] == ' ')
		map_data->index++;
	if (map[map_data->index] >= '1' || map[map_data->index] <= '9')
		extract_res(map_data, map, 'y');
	else
		on_error(4);
	map_data->index = skip_empty_space(map_data->index, map);
	if (map[map_data->index] != '\n')
		on_error(4);
	check_max_res(map_data, 0);
	ft_putstr("Extracted resolution \xE2\x9C\x94\n");
}
