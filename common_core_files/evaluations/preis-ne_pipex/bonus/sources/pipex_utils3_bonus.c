/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:01:32 by preis-ne          #+#    #+#             */
/*   Updated: 2024/06/25 03:50:44 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_wordsquotes(char *str, int c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\'' || str[i] == '\"')
			n++;
		else if (str[i] != '\0')
			n++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (n);
}

int	ft_len(char *s, char c)
{
	int	len;

	len = 0;
	if (s[len] == '\'' || s[len] == '\"')
	{
		if (s[len] == '\'')
		{
			len++;
			while (s[len] != '\'' && s[len] != '\0')
				len++;
			len++;
		}
		else if (s[len] == '\"')
		{
			len++;
			while (s[len] != '\"' && s[len] != '\0')
				len++;
			len++;
		}
	}
	else
		while (s[len] && s[len] != c)
			len++;
	return (len);
}

char	*ft_strtrim_quotes(char *s, int start, int len)
{
	char	*str;
	int		lens;
	int		i;
	int		j;

	i = -1;
	j = 0;
	lens = ft_strlen(s);
	if (start > lens)
		return (ft_strdup(""));
	if (start + len > lens)
		len = lens - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (++i < len)
		str[j++] = s[start + i];
	str[j] = '\0';
	return (str);
}
