/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:06:07 by anonymous      #+#    #+#                */
/*   Updated: 2019/11/08 11:37:51 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p1;

	p1 = (char *)&c;
	while (*s)
	{
		if (*s == (char)c)
			p1 = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else if (p1 == (char *)&c)
		return (NULL);
	return ((char *)p1);
}
