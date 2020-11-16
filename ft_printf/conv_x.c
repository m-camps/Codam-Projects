/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:06 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:31:45 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	write_x(t_data data)
{
	if (data.padding == 1 && data.precision == 0)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	data.width_data--;
	data.tmp_count++;
	return (data);
}

static	t_data	precision_x(char *str, t_data data)
{
	int	i;

	i = 0;
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
	}
	else
	{
		ft_putstr_fd(str, 1);
		data.tmp_count = data.tmp_count + ft_strlen(str);
	}
	return (data);
}

static	t_data	width_x(char *str, t_data data)
{
	if (data.precision == 1 && data.precision_data > (int)ft_strlen(str))
		data.width_data = data.width_data - data.precision_data;
	else
		data.width_data = data.width_data - (int)ft_strlen(str);
	while (data.justify != 1 && data.width_data > 0)
		data = write_x(data);
	data = precision_x(str, data);
	while (data.width_data > 0)
		data = write_x(data);
	return (data);
}

t_data			conv_x(va_list arg, t_data data)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(arg, unsigned int);
	if (data.precision == 1 && data.precision_data == 0 && nb == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base((unsigned long)nb, 16);
	if (!str)
		return (on_error(data));
	if (data.hex_case == -1)
		str = ft_toupper_str(str);
	data = width_x(str, data);
	free(str);
	return (data);
}
