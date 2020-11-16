/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:21:43 by anonymous      #+#    #+#                */
/*   Updated: 2019/11/14 16:41:31 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (i <= len - 1 && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] == needle[j] && i <= len - 1)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)(haystack + i - j));
			}
			j++;
			i++;
		}
		if (j > 0)
			i--;
		i++;
	}
	return (0);
}
