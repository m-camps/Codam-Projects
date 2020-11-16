/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:17 by mcamps         #+#    #+#                */
/*   Updated: 2020/01/07 18:02:05 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_data	data_precision_format(t_data data, char *format)
{
	int width;

	width = 0;
	while (format[data.index] >= '0' && format[data.index] <= '9')
	{
		if (format[data.index] == '0')
			width = (width * 10);
		else
			width = (format[data.index] - '0') + (width * 10);
		data.index++;
	}
	data.precision_data = width;
	data.index--;
	return (data);
}

t_data			data_precision(t_data data, va_list arg, char *format)
{
	data.index++;
	data.precision = 1;
	if (format[data.index] == '*')
	{
		data.precision_data = va_arg(arg, int);
		if (data.precision_data < 0)
		{
			data.precision = 0;
			data.precision_data = 0;
		}
	}
	else
		data = data_precision_format(data, format);
	return (data);
}
