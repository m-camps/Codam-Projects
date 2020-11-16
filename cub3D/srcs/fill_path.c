/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 20:04:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/12 20:28:32 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_path(t_map_data *map_data, char type, char *path)
{
	if (open(path, O_RDONLY) == -1)
		on_error(5);
	if (type == 'N')
		map_data->n_path = path;
	if (type == 'S')
		map_data->s_path = path;
	if (type == 'W')
		map_data->w_path = path;
	if (type == 'E')
		map_data->e_path = path;
	if (type == 'T')
		map_data->spr_path = path;
}

void	extract_path(t_map_data *map_data, char *map, char type, int path_end)
{
	int		i;
	char	*path;

	i = 0;
	path = (char*)malloc(sizeof(char) * ((path_end - map_data->index) + 1));
	if (!path)
		on_error(9);
	while (map_data->index < path_end)
	{
		path[i] = map[map_data->index];
		map_data->index++;
		i++;
	}
	path[i] = '\0';
	fill_path(map_data, type, path);
}

void	check_double(t_map_data *map_data, char type)
{
	if (map_data->n_path && type == 'N')
		on_error(6);
	if (map_data->s_path && type == 'S')
		on_error(6);
	if (map_data->w_path && type == 'W')
		on_error(6);
	if (map_data->e_path && type == 'E')
		on_error(6);
	if (map_data->spr_path && type == 'T')
		on_error(6);
}

int		get_file_path_length(char *map, int i)
{
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	i--;
	while (map[i] == ' ')
		i--;
	i++;
	return (i);
}

void	get_path(t_map_data *map_data, char *map, char type)
{
	int		i;

	check_double(map_data, type);
	if (type == 'T')
		map_data->index++;
	else
		map_data->index += 2;
	map_data->index = skip_empty_space(map_data->index, map);
	i = get_file_path_length(map, map_data->index);
	extract_path(map_data, map, type, i);
	map_data->index = skip_empty_space(map_data->index, map);
	ft_putstr("Extracted texture path: ");
	write(1, &type, 1);
	ft_putstr(" \xE2\x9C\x94 \n");
}
