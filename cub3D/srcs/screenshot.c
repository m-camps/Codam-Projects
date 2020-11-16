/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 19:19:18 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/09 21:27:05 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(int n)
{
	if (n < 0)
		on_error(12);
}

void	header(int fd, t_meta_data *meta)
{
	unsigned int		temp;
	static const int	zero[24];
	int					n;

	n = 0;
	n = write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	error(n);
	n = write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	error(n);
	temp = (unsigned int)meta->map.res_x;
	n = write(fd, &temp, 4);
	error(n);
	temp = (unsigned int)meta->map.res_y;
	n = write(fd, &temp, 4);
	error(n);
	n = write(fd, "\x01\x00\x18\x00", 4);
	error(n);
	n = write(fd, zero, 24);
	error(n);
}

void	pixel(int fd, t_meta_data *meta, int x, int y)
{
	int				n;
	int				color;
	unsigned int	rgb;

	n = 0;
	color = *(int*)(meta->mlx.addr + (y * meta->mlx.ls) + \
		(x * (meta->mlx.bpp / 8)));
	rgb = (color & 0x000000FF);
	n = write(fd, &rgb, 1);
	error(n);
	rgb = ((color & 0x0000FF00) >> 8);
	n = write(fd, &rgb, 1);
	error(n);
	rgb = ((color & 0x00FF0000) >> 16);
	n = write(fd, &rgb, 1);
	error(n);
}

void	fill_bmp(int fd, t_meta_data *meta, int x, int y)
{
	int				padding_size;
	int				n;
	unsigned int	padding;

	padding = 0;
	padding_size = (4 - (meta->map.res_x * 3) % 4) % 4;
	while (y >= 0)
	{
		x = 0;
		while (x < meta->map.res_x)
		{
			pixel(fd, meta, x, y);
			x++;
		}
		if (padding_size > 0)
		{
			n = write(fd, "\x00\x00\x00", padding_size);
			error(n);
		}
		y--;
	}
}

void	screenshot(t_meta_data *meta)
{
	int		fd;
	int		y;
	int		x;

	x = 0;
	y = meta->map.res_y - 1;
	ft_putstr("Making screenshot...\n");
	fd = open("capture.bmp", (O_WRONLY | O_CREAT | O_TRUNC | O_APPEND), 0666);
	if (fd == -1)
		on_error(6);
	header(fd, meta);
	fill_bmp(fd, meta, x, y);
	ft_putstr("Screenshot saved in file capture.bmp\n");
	exit_hook(meta);
}
