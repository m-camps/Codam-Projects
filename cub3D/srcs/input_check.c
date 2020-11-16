/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/08 19:05:40 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/08 19:15:10 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_screenshot(char *av)
{
	if (av[0] != '-')
		return (1);
	if (av[1] != '-')
		return (1);
	if (av[2] != 's')
		return (1);
	if (av[3] != 'a')
		return (1);
	if (av[4] != 'v')
		return (1);
	if (av[5] != 'e')
		return (1);
	if (av[6] != '\0')
		return (1);
	return (0);
}

int		check_cub(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (av[i - 1] != 'b')
		return (1);
	if (av[i - 2] != 'u')
		return (1);
	if (av[i - 3] != 'c')
		return (1);
	if (av[i - 4] != '.')
		return (1);
	return (0);
}

void	argument_check(int ac, char **av, t_map_data *map)
{
	if (ac == 1 || ac > 3 || check_cub(av[1]) == 1)
		on_error(11);
	if (ac == 3)
	{
		if (check_screenshot(av[2]))
			on_error(11);
		else
			map->screenshot = 1;
	}
}
