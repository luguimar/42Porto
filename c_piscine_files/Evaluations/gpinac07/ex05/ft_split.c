/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:41:02 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 03:49:23 by gpina-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index] != '\0')
	{
		if (charset[index] == c)
			return (0);
		index++;
	}
	return (1);
}

int	count_words(char *str, char *charset)
{
	int	index;
	int	words;

	words = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0)
		{
			if (check_sep(str[index], charset) == 1)
				words++;
		}
		if (check_sep(str[index], charset) == 1
			&& check_sep(str[index - 1], charset) == 0)
			words++;
		index++;
	}
	return (words);
}

int	ft_strlenword(char *str, char *charset)
{
	int	index;

	index = 0;
	while (str[index] != '\0' && check_sep(str[index], charset) == 1)
		index++;
	return (index);
}

char	*ft_strdup(char *str, char *charset)
{
	int		index;
	char	*cpy;
	int		size;

	size = ft_strlenword(str, charset);
	cpy = (char *)malloc(sizeof (*cpy) * (size + 1));
	if (!cpy)
		return (0);
	index = 0;
	while (index < size)
	{
		cpy[index] = str[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	char	**split;
	int		sizesplit;

	sizesplit = count_words(str, charset);
	split = (char **)malloc(sizeof (*split) * (sizesplit + 1));
	if (!split)
		return (0);
	index = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && check_sep(*str, charset) == 0)
			str++;
		if (*str != '\0')
		{
			split[index] = ft_strdup(str, charset);
			index++;
		}
		while (*str != '\0' && check_sep(*str, charset) == 1)
			str++;
	}
	split[index] = 0;
	return (split);
}
