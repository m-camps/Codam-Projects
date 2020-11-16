/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:37 by mcamps         #+#    #+#                */
/*   Updated: 2020/03/09 13:09:20 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		fill_condition(char *format, t_data data)
{
	if (format[data.index] == 'c' || format[data.index] == 's' || \
		format[data.index] == 'd' || format[data.index] == 'i' || \
		format[data.index] == 'x' || format[data.index] == 'X' || \
		format[data.index] == 'u' || format[data.index] == 'p' || \
		format[data.index] == '%')
		return (0);
	return (1);
}

static	t_data	conversion_data(char *format, t_data data)
{
	if (format[data.index] == 'c')
		data.conversion = 'c';
	if (format[data.index] == 's')
		data.conversion = 's';
	if (format[data.index] == 'd' || format[data.index] == 'i')
		data.conversion = 'd';
	if (format[data.index] == 'p')
		data.conversion = 'p';
	if (format[data.index] == 'u')
		data.conversion = 'u';
	if (format[data.index] == '%')
		data.conversion = '%';
	if (format[data.index] == 'x')
	{
		data.conversion = 'x';
		data.hex_case = 1;
	}
	if (format[data.index] == 'X')
	{
		data.conversion = 'X';
		data.hex_case = -1;
	}
	return (data);
}

t_data			fill_data(t_data data, va_list arg, char *format)
{
	data.index++;
	while (fill_condition(format, data) == 1 && format[data.index] != '\0')
	{
		if (format[data.index] == '0')
			data.padding = 1;
		else if (format[data.index] == '-')
			data.justify = 1;
		else if (format[data.index] == '*')
			data = data_width_arg(data, arg);
		else if (format[data.index] >= '0' && format[data.index] <= '9')
			data = data_width(data, format);
		else if (format[data.index] == '.')
			data = data_precision(data, arg, format);
		data.index++;
	}
	if (data.padding == 1 && data.justify == 1)
		data.padding = 0;
	data = conversion_data(format, data);
	if (data.padding == 1 && (data.conversion == 'd' || data.conversion == 'i')\
		&& data.precision == 1 && data.width == 1)
		data.padding = 0;
	if (data.conversion == '0')
		return (on_error(data));
	return (data);
}
