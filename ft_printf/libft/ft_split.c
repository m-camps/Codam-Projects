/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 10:16:21 by anonymous      #+#    #+#                */
/*   Updated: 2019/11/14 16:32:14 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (count + 1);
}

static int	free_array(char **str, int y)
{
	int i;

	i = 0;
	if (!str[y])
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		if (str)
			free(str);
		return (0);
	}
	return (1);
}

static	int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (len);
		len++;
		i++;
	}
	return (len);
}

static char	**ft_fill(char const *s, char **str, char c, int y)
{
	int		i;
	int		x;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		x = 0;
		str[y] = (char*)malloc(sizeof(char*) * (word_len(s, c, i) + 1));
		if (free_array(str, y) == 0)
			return (NULL);
		while (s[i] != c && s[i] != '\0')
		{
			str[y][x] = s[i];
			i++;
			x++;
		}
		str[y][x] = '\0';
		y++;
	}
	str[y] = NULL;
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		y;

	y = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (!str)
		return (0);
	str = ft_fill(s, str, c, y);
	return (str);
}
