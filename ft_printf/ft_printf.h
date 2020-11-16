/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 13:30:59 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:41:24 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_data
{
	int				index;
	int				tmp_count;
	int				count;
	int				justify;
	int				padding;
	int				precision;
	int				precision_data;
	int				width;
	int				width_data;
	char			conversion;
	int				hex_case;
	int				error;
	int				sign;
}					t_data;

int					ft_printf(char *format, ...);
char				*ft_toupper_str(char *str);
void				ft_putnbr_fd_u(unsigned int n, int fd);
char				*ft_itoa_u(unsigned int n);
t_data				on_error(t_data data);
t_data				conv_s(va_list arg, t_data data);
t_data				conv_c(va_list arg, t_data data);
t_data				conv_d(va_list arg, t_data data);
t_data				conv_u(va_list arg, t_data data);
t_data				conv_p(va_list arg, t_data data);
t_data				conv_x(va_list arg, t_data data);
t_data				data_width_arg(t_data data, va_list arg);
t_data				data_width(t_data data, char *format);
t_data				data_precision(t_data data, va_list arg, char *format);
t_data				init_struct(void);
t_data				reset_data(t_data data);
t_data				fill_data(t_data data, va_list arg, char *format);
#endif
