/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:32:57 by mcamps         #+#    #+#                */
/*   Updated: 2020/01/07 17:44:12 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill(unsigned long n, int len, char *str, int base)
{
	int		i;

	i = len;
	str[i] = '\0';
	i--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		if (n % base < 10)
			str[i] = (n % base) + '0';
		else
			str[i] = (n % base) + 'a' - 10;
		i--;
		n = n / base;
	}
	return (str);
}

static int		nb_len(unsigned long nb, int base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(unsigned long nb, int base)
{
	int		len;
	char	*str;

	len = nb_len(nb, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	return (fill(nb, len, str, base));
}
