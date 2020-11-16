/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:09:01 by mcamps         #+#    #+#                */
/*   Updated: 2019/11/08 11:37:51 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d == 0 && s == 0 && n > 0)
		return (dst);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (d);
}
