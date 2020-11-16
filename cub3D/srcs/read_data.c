/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:27:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/08 19:48:07 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_from_file(int fd, char *dst)
{
	char	*buff;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		buff = (char*)malloc(sizeof(char) * 1001);
		if (!buff)
			on_error(9);
		ret = read(fd, buff, 1000);
		if (ret < 0)
			on_error(12);
		buff[ret] = '\0';
		dst = ft_strjoin(dst, buff);
		if (!dst)
			on_error(9);
	}
	return (dst);
}

void	read_data(t_map_data *map_data, char *map_path)
{
	int		fd;
	char	*map;

	ft_putstr("Reading map data...\n");
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		on_error(5);
	map = ft_strdup("");
	if (!map)
		on_error(9);
	map = read_from_file(fd, map);
	parse_data(map_data, map);
	free(map);
	ft_putstr("Map data correct \xE2\x9C\x94\xE2\x9C\x94\n");
}
