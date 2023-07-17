/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:20:45 by luguimar          #+#    #+#             */
/*   Updated: 2023/06/12 02:18:38 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * len + 1);
	dst[len] = '\0';
	d = dst;
	s = src;
	if (d <= s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + len;
		s = s + len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, char c)
{
	int		i;
	char	*pointer;

	if (!s)
		return (NULL);
	pointer = (char *) s;
	i = 0;
	if (c == '\0')
	{
		while (s[i] != c)
			i++;
		return (pointer + i);
	}
	else
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (NULL);
	}
	return (pointer + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1)
		str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
	}
	j = -1;
	while (s2[++j] != '\0')
		str[++i] = s2[j];
	str[i] = '\0';
	return (str);
}
