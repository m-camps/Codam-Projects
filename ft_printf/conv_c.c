/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:29:20 by mcamps         #+#    #+#                */
/*   Updated: 2020/03/06 13:57:58 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	write_c(t_data data)
{
	if (data.padding == 1)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	data.width_data--;
	data.tmp_count++;
	return (data);
}

static	t_data	width_c(char c, t_data data)
{
	if (data.width == 1 && data.width_data != 0)
		data.width_data = data.width_data - 1;
	while (data.justify != 1 && data.width_data != 0)
		data = write_c(data);
	ft_putchar_fd(c, 1);
	data.tmp_count++;
	while (data.width_data != 0)
		data = write_c(data);
	return (data);
}

static	t_data	print_null_term(char c, t_data data)
{
	if (data.width == 1 && data.width_data != 0)
		data.tmp_count = data.width_data;
	else
		data.tmp_count = 1;
	while (data.width_data > 1 && data.justify == 0)
	{
		if (data.padding == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data.width_data--;
	}
	write(1, &c, 1);
	while (data.width_data > 1)
	{
		if (data.padding == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data.width_data--;
	}
	return (data);
}

t_data			conv_c(va_list arg, t_data data)
{
	int		c;

	if (data.conversion == 'c')
		c = va_arg(arg, int);
	else
		c = '%';
	if (c == '\0')
		return (print_null_term(c, data));
	if (!c)
		return (on_error(data));
	data = width_c(c, data);
	return (data);
}
