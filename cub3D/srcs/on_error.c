/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   on_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:41:17 by anonymous     #+#    #+#                 */
/*   Updated: 2020/10/09 17:38:35 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_error_2(int error_code)
{
	if (error_code == 10)
		ft_putstr("Texture incorrect\n");
	if (error_code == 11)
		ft_putstr("Arguments incorrect\n");
	if (error_code == 12)
		ft_putstr("Write failed\n");
	exit(0);
}

void	on_error(int error_code)
{
	ft_putstr("Error\n");
	if (error_code == 1)
		ft_putstr("Map incorrect\n");
	if (error_code == 2)
		ft_putstr("Color incorrect\n");
	if (error_code == 3)
		ft_putstr("MLX Failed\n");
	if (error_code == 4)
		ft_putstr("Resolution incorrect\n");
	if (error_code == 5)
		ft_putstr("Filepath incorrect\n");
	if (error_code == 6)
		ft_putstr("Duplicate data\n");
	if (error_code == 7)
		ft_putstr("Data incomplete\n");
	if (error_code == 8)
		ft_putstr("Incorrect identifier\n");
	if (error_code == 9)
		ft_putstr("Malloc failed\n");
	on_error_2(error_code);
}
