/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data_w.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:27 by mcamps         #+#    #+#                */
/*   Updated: 2020/01/08 13:35:22 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	data_width_arg(t_data data, va_list arg)
{
	int value;

	data.width = 1;
	value = va_arg(arg, int);
	if (value < 0)
	{
		value = -value;
		data.justify = 1;
	}
	data.width_data = value;
	return (data);
}

t_data	data_width(t_data data, char *format)
{
	int width;

	width = 0;
	data.width = 1;
	while (format[data.index] >= '0' && format[data.index] <= '9')
	{
		if (format[data.index] == '0')
			width = (width * 10);
		else
			width = (format[data.index] - '0') + (width * 10);
		data.index++;
	}
	data.width_data = width;
	data.index--;
	return (data);
}
