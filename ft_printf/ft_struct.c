/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:31:09 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:28:21 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init_struct(void)
{
	t_data data;

	data.index = 0;
	data.count = 0;
	data.tmp_count = 0;
	data.justify = 0;
	data.padding = 0;
	data.precision = 0;
	data.precision_data = 0;
	data.width = 0;
	data.width_data = 0;
	data.conversion = '0';
	data.hex_case = 0;
	data.error = 0;
	data.sign = 0;
	return (data);
}

t_data	reset_data(t_data data)
{
	data.tmp_count = 0;
	data.justify = 0;
	data.padding = 0;
	data.precision = 0;
	data.precision_data = 0;
	data.width = 0;
	data.width_data = 0;
	data.conversion = '0';
	data.hex_case = 0;
	data.sign = 0;
	return (data);
}
