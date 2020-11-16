/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:29:53 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:32:04 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	write_s(t_data data)
{
	if (data.padding == 1)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	data.width_data--;
	data.tmp_count++;
	return (data);
}

static	t_data	precision_s(char *str, t_data data)
{
	int	i;

	i = 0;
	if (data.precision == 1 && data.precision_data < (int)ft_strlen(str))
	{
		while (data.precision_data > 0)
		{
			ft_putchar_fd(str[i], 1);
			i++;
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

static	t_data	width_s(char *str, t_data data)
{
	if (data.precision == 1 && data.precision_data < (int)ft_strlen(str))
		data.width_data = data.width_data - data.precision_data;
	else
		data.width_data = data.width_data - (int)ft_strlen(str);
	while (data.justify != 1 && data.width_data > 0)
		data = write_s(data);
	data = precision_s(str, data);
	while (data.width_data > 0)
		data = write_s(data);
	return (data);
}

t_data			conv_s(va_list arg, t_data data)
{
	char	*tmp;
	char	*str;

	tmp = va_arg(arg, char*);
	if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
	if (!str)
		return (on_error(data));
	data = width_s(str, data);
	free(str);
	return (data);
}
