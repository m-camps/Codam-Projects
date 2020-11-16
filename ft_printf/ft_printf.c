/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:51 by mcamps         #+#    #+#                */
/*   Updated: 2020/01/20 16:54:37 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	ft_write(va_list arg, t_data data)
{
	if (data.conversion == 'c' || data.conversion == '%')
		data = conv_c(arg, data);
	if (data.conversion == 's')
		data = conv_s(arg, data);
	if (data.conversion == 'd' || data.conversion == 'i')
		data = conv_d(arg, data);
	if (data.conversion == 'x' || data.conversion == 'X')
		data = conv_x(arg, data);
	if (data.conversion == 'p')
		data = conv_p(arg, data);
	if (data.conversion == 'u')
		data = conv_u(arg, data);
	return (data);
}

int				ft_printf(char *format, ...)
{
	va_list		arg;
	t_data		data;

	va_start(arg, format);
	data = init_struct();
	while (format[data.index] != '\0' && data.error != -1)
	{
		if (format[data.index] == '%')
		{
			data = fill_data(data, arg, format);
			data = ft_write(arg, data);
			data.count = data.tmp_count + data.count;
			data = reset_data(data);
		}
		else
		{
			ft_putchar_fd(format[data.index], 1);
			data.count++;
		}
		data.index++;
	}
	va_end(arg);
	data.count = (data.error == -1) ? data.error : data.count;
	return (data.count);
}
