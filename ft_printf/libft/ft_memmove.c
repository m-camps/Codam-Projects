/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:10:46 by mcamps         #+#    #+#                */
/*   Updated: 2019/11/08 14:06:50 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move(char *d, const char *s, size_t len)
{
	if (d < s)
	{
		while (len > 0)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	}
	else
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len > 0)
		{
			*d = *s;
			s--;
			d--;
			len--;
		}
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst == 0 && src == 0 && len > 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	ft_move(d, s, len);
	return (dst);
}
