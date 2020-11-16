/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 10:14:45 by anonymous      #+#    #+#                */
/*   Updated: 2019/11/14 15:32:13 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	startpos(const char *s1, const char *set)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	endpos(const char *s1, const char *set)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s1[i + 1] != '\0')
		i++;
	while (set[j] != '\0' && i != 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start = startpos(s1, set);
	end = endpos(s1, set);
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
