/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:31:18 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:41:10 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_toupper_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

t_data	on_error(t_data data)
{
	data.error = -1;
	return (data);
}
