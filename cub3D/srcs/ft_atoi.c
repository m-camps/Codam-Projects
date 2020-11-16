/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 17:50:00 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/12 20:55:50 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi(const char *str, int i)
{
	unsigned long	total;
	int				sign;

	sign = 1;
	total = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		if (total > 2147483647)
			return (sign * 2147483647);
		i++;
	}
	if (total > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return (sign * total);
}
