/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 12:52:49 by mcamps         #+#    #+#                */
/*   Updated: 2020/02/05 15:33:26 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*fill(unsigned int n, int len, char *str)
{
	int		i;

	i = len;
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (str);
}

static unsigned int	nb_len(unsigned int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = nb_len(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (fill(n, len, str));
}
