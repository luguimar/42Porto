/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:05:13 by luguimar          #+#    #+#             */
/*   Updated: 2023/07/12 00:07:02 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	size_t	strlength;
	char	*str;

	i = start;
	strlength = 0;
	if (start >= ft_strchrnum(s, '\0'))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		*str = '\0';
		free(s);
		return (str);
	}
	while (s[i] != '\0' && strlength < len)
	{
		i++;
		strlength++;
	}
	str = malloc(sizeof(char) * strlength + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, strlength + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	lenghts;

	i = 0;
	lenghts = ft_strchrnum(src, '\0');
	if (dstsize)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		free(src);
	}
	return (lenghts);
}

int	ft_strchrnum(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char) c;
	if (c1 == '\0')
	{
		while (s[i] != c1)
			i++;
		return (i);
	}
	else
	{
		while (s[i] != c1 && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (-1);
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strchrnum(s1, '\0') + ft_strchrnum(s2, '\0') + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
