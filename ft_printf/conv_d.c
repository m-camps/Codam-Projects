/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_d.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:29:31 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:32:08 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	write_d(t_data data)
{
	if (data.padding == 1 && data.precision == 0)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	data.width_data--;
	data.tmp_count++;
	return (data);
}

static	t_data	precision_d(char *str, t_data data)
{
	int	i;

	i = 0;
	if (data.sign == 1 && data.padding == 0)
		ft_putchar_fd('-', 1);
	if (data.precision == 1 && data.precision_data > (int)ft_strlen(str))
	{
		while (str[i] != '\0')
		{
			if (data.precision_data <= (int)ft_strlen(str))
			{
				ft_putchar_fd(str[i], 1);
				i++;
			}
			else
				ft_putchar_fd('0', 1);
			data.tmp_count++;
			data.precision_data--;
		}
		return (data);
	}
	ft_putstr_fd(str, 1);
	data.tmp_count = data.tmp_count + ft_strlen(str);
	return (data);
}

static	t_data	width_d(char *str, t_data data)
{
	if (data.precision == 1 && data.precision_data > (int)ft_strlen(str))
		data.width_data = data.width_data - data.precision_data;
	else
		data.width_data = data.width_data - (int)ft_strlen(str);
	if (data.sign == 1)
	{
		data.width_data -= 1;
		data.count++;
	}
	if (data.padding == 1 && data.sign == 1)
		ft_putchar_fd('-', 1);
	while (data.justify != 1 && data.width_data > 0)
		data = write_d(data);
	data = precision_d(str, data);
	while (data.width_data > 0)
		data = write_d(data);
	return (data);
}

t_data			conv_d(va_list arg, t_data data)
{
	int		nb;
	char	*str;

	nb = va_arg(arg, int);
	if (nb < 0)
	{
		data.sign = 1;
		nb = -nb;
	}
	if (data.precision == 1 && data.precision_data == 0 && nb == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_u(nb);
	if (!str)
		return (on_error(data));
	data = width_d(str, data);
	free(str);
	return (data);
}
