/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:29:45 by mcamps         #+#    #+#                */
/*   Updated: 2020/01/20 16:52:19 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	write_p(t_data data)
{
	if (data.padding == 1)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	data.width_data--;
	data.tmp_count++;
	return (data);
}

static	t_data	precision_p(char *str, t_data data)
{
	int	i;

	i = 0;
	ft_putstr_fd("0x", 1);
	if (data.precision == 1)
	{
		while (data.precision_data > 0)
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

static	t_data	width_p(char *str, t_data data)
{
	data.width_data = data.width_data - (int)ft_strlen(str) - 2;
	while (data.justify != 1 && data.width_data > 0)
		data = write_p(data);
	data = precision_p(str, data);
	while (data.width_data > 0)
		data = write_p(data);
	return (data);
}

t_data			conv_p(va_list arg, t_data data)
{
	unsigned long	p;
	char			*str;

	p = va_arg(arg, unsigned long);
	if ((void *)p == NULL && data.precision == 1)
		str = ft_strdup("");
	else
		str = ft_itoa_base(p, 16);
	if (!str)
		return (on_error(data));
	data = width_p(str, data);
	data.tmp_count += 2;
	free(str);
	return (data);
}
