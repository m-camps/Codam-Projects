/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_color.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 17:27:51 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/12 20:48:18 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		create_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static	int		extract_color(t_map_data *map_data, char *map)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * 3 + 1);
	if (!str)
		on_error(9);
	if (!(map[map_data->index] >= '0' && map[map_data->index] <= '9'))
		on_error(2);
	while (map[map_data->index] >= '0' && map[map_data->index] <= '9')
	{
		str[i] = map[map_data->index];
		i++;
		map_data->index++;
	}
	str[i] = '\0';
	ret = ft_atoi(str, 0);
	if (ret > 255 || ret < 0)
		on_error(2);
	free(str);
	return (ret);
}

static	void	check_color(int i, char *map)
{
	int		comma;
	int		value;

	comma = 0;
	value = 0;
	while (map[i] != '\n' && map[i] != '\0')
	{
		while (map[i] == ' ' && map[i + 1] != '\n')
			i++;
		if (map[i] >= '0' && map[i] <= '9')
			value++;
		if (map[i] == ',')
		{
			comma++;
			value = 0;
		}
		if (value > 3)
			on_error(2);
		i++;
	}
	if (comma != 2)
		on_error(2);
}

void			check_double_color(t_map_data *map_data, char type)
{
	if (map_data->floor && type == 'F')
		on_error(6);
	if (map_data->ceiling && type == 'C')
		on_error(6);
	if (type == 'C')
		map_data->c_check = 1;
	if (type == 'F')
		map_data->f_check = 1;
}

void			get_color(t_map_data *map_data, char *map, char type)
{
	int r;
	int g;
	int b;

	check_color(map_data->index, map);
	check_double_color(map_data, type);
	map_data->index++;
	while (map[map_data->index] == ' ')
		map_data->index++;
	r = extract_color(map_data, map);
	while (map[map_data->index] == ' ' || map[map_data->index] == ',')
		map_data->index++;
	g = extract_color(map_data, map);
	while (map[map_data->index] == ' ' || map[map_data->index] == ',')
		map_data->index++;
	b = extract_color(map_data, map);
	while (map[map_data->index] != '\n' && map[map_data->index] == ' ')
		map_data->index++;
	if (type == 'F')
		map_data->floor = create_rgb(r, g, b);
	if (type == 'C')
		map_data->ceiling = create_rgb(r, g, b);
	ft_putstr("Extracted color: ");
	write(1, &type, 1);
	ft_putstr(" \xE2\x9C\x94 \n");
}
