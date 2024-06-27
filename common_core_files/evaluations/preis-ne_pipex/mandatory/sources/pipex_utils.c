/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 06:55:50 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/25 03:17:45 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

char	*ft_strtrim_quotes_ends(char *s, int start, int len)
{
	char	*str;
	int		lens;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	if (start + len > lens)
		len = lens - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i++ < (len -2))
		str[j++] = s[start + i];
	str[j] = '\0';
	return (str);
}

char	*ft_removequotes(char *str, int c)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = 0;
	temp = malloc(sizeof(char) + ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	ft_bzero(temp, ft_strlen(str) + 1);
	while (str[++i])
	{
		if (str[i] != c)
			temp[j++] = str[i];
	}
	free(str);
	temp[i] = '\0';
	return (temp);
}

void	ft_trim(char *str, char **split, int *i, int *j)
{
	if (str[*j] == '\"')
	{
		split[*i] = ft_strtrim_quotes_ends(str, *j, ft_len(&str[*j], '\"'));
		if (!split[*i])
			ft_free(split);
	}
	else if (str[*j] == '\'')
	{
		split[*i] = ft_strtrim_quotes_ends(str, *j, ft_len(&str[*j], '\''));
		if (!split[*i])
			ft_free(split);
	}
	(*j)++;
}

char	**ft_split_remove_quotes(char *str, char c, char **split, int words)
{
	int	i;

	i = -1;
	auto int j = 0;
	while (++i < words)
	{
		while (str[j] && str[j] == c)
			j++;
		if (str[j] == '\'' || str[j] == '\"')
			ft_trim(str, split, &i, &j);
		else if (str[j] != '\"' || str[j] != '\'')
		{
			split[i] = ft_strtrim_quotes(str, j, ft_len(&str[j], c));
			if (ft_strchr(split[i], '\''))
				split[i] = ft_removequotes(split[i], '\'');
			else if (ft_strchr(split[i], '\"'))
				split[i] = ft_removequotes(split[i], '\"');
			if (!split[i])
				ft_free(split);
		}
		while (str[j] && str[j] != c)
			j++;
	}
	return (split[i] = 0, split);
}

char	**ft_splitquotes(char *str, int c)
{
	char	**split;
	int		words;

	if (!str)
		return (0);
	words = ft_wordsquotes(str, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (0);
	split = ft_split_remove_quotes(str, c, split, words);
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	auto char **arr = ft_splitquotes("\"coi's'a do carago\"", ' ');
	auto int i = -1;
	while (arr[++i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
	}
	free(arr);
	return (0);
}*/
