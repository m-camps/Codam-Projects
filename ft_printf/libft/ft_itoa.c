/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 10:21:08 by anonymous      #+#    #+#                */
/*   Updated: 2019/11/13 17:55:50 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill(int n, int len, char *str)
{
	int		i;
	int		sign;

	i = len;
	sign = 1;
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

static int		nb_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = nb_len(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (fill(n, len, str));
}
