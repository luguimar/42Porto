/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:46:24 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/22 04:06:57 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	int	wordcount;
	int	i;
	int	singlequote;
	int	doublequote;

	if (!s)
		return (-1);
	i = 0;
	singlequote = 0;
	doublequote = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' && doublequote == 0)
			singlequote = 1;
		if (s[i] == '"' && singlequote == 1)
			singlequote = 0;
		if (s[i] == '\'' && singlequote == 0)
			doublequote = 1;
		if (s[i] == '\'' && doublequote == 1)
			doublequote = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')
			&& singlequote == 0 && doublequote == 0)
			wordcount++;
		i++;
	}
	if (doublequote == 0 && singlequote == 0)
		return (wordcount);
	return (-1);
}

static void	wordfiller(char *j, char *str, char c)
{
	int	i;
	int	singlequote;
	int	doublequote;

	i = 0;
	singlequote = 0;
	doublequote = 0;
	while (j[i] != '\0')
	{
		if (j[i] == '\'' && singlequote == 0 && doublequote == 0)
		{
			j++;
			singlequote = 1;
		}
	}
	while ((j[i] != '\0' && j[i] != c) || (singlequote == 1 || doublequote == 1))
	{
		str[i] = j[i];
		i++;
	}
	str[i] = '\0';
}

static void	strfiller(char *s, char **str, char c)
{
	int	i;
	int	j;
	int	k;
	int	nextc;
	int     quotes[2];

	i = 0;
	k = 0;
	nextc = 0;
	quotes[0] = 0;
	quotes[1] = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' && quotes[1] == 0)
			quotes[0] = 1;
		if (s[i] == '"' && quotes[0] == 1)
			quotes[0] == 0;
		if (s[i] == '\'' && quotes[0] == 0)
			quotes[1] = 1;
		if (s[i] == '\'' && quotes[1] == 1)
			quotes[1] = 0;
		if ((s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')) && quotes[0] == 0 && quotes[1] == 0)
		{
			j = i + 1;
			while (--j >= nextc)
			{
				if (s[j] == '"' && quotes[1] == 0)
					quotes[0] = 1;
				if (s[j] == '"' && quotes[0] == 1)
					quotes[0] == 0;
				if (s[j] == '\'' && quotes[0] == 0)
					quotes[1] = 1;
				if (s[j] == '\'' && quotes[1] == 1)
					quotes[1] = 0;
				if (((j == 0 && s[j] != c) || s[j - 1] == c) && quotes[0] + quotes[1] == 0)
				{
					nextc = j + 1;
					wordfiller(s + j, str[k], c);
					k++;
				}
			}
		}
		i++;
	}
}

static void	strmalloc(int *j, char ***str, int *k)
{
	(*str)[*k] = malloc((*j + 1) * sizeof(char));
	if (!(*str)[*k])
	{
		while (*k > 0)
		{
			*k = (*k) - 1;
			free((void *)(*str)[*k]);
			(*str)[*k] = NULL;
		}
		free(*str);
		*str = NULL;
	}
	*k = (*k) + 1;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;
	int	quotes[2];

	i = -1;
	j = 1;
	k = 0;
	quotes[0] = 0;
	quotes[1] = 0;
	str = malloc((wordcounter(s, c) + 1) * sizeof(char *));
	if (!str || !s || wordcounter(s, c) == -1)
		return (NULL);
	str[wordcounter(s, c)] = NULL;
	while (s[++i] != '\0')
	{
		if (s[i] == '"' && quotes[1] == 0)
			quotes[0] = 1;
		if (s[i] == '"' && quotes[0] == 1)
			quotes[0] == 0;
		if (s[i] == '\'' && quotes[0] == 0)
			quotes[1] = 1;
		if (s[i] == '\'' && quotes[1] == 1)
			quotes[1] = 0;
		if ((s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')) && quotes[0] == 0 && quotes[1] == 0)
		{
			strmalloc(&j, &str, &k);
			if (!str)
				return (NULL);
		}
		if (s[i] != c || quotes[0] == 1 || quotes[1] == 1)
			j++;
	}
	strfiller((char *)s, str, c);
	return (str);
}
