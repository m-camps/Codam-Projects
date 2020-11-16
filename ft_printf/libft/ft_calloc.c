/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:54:01 by mcamps         #+#    #+#                */
/*   Updated: 2019/11/08 15:15:30 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	len = size * count;
	s = (char *)malloc(len);
	if (!s)
		return (0);
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
