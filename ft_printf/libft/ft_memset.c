/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:18:56 by mcamps         #+#    #+#                */
/*   Updated: 2019/11/08 11:37:51 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)b;
	while (len > 0)
	{
		p[i] = c;
		i++;
		len--;
	}
	return (b);
}
