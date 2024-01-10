/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:27:47 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:02:46 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	trigger;

	i = 0;
	counter = 0;
	trigger = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			trigger = 0;
		else if (s[i] != c && trigger == 0)
		{
			counter++;
			trigger = 1;
		}
		i++;
	}
	return (counter);
}

int	len_word(char const *word, char sep)
{
	int	i;

	i = 0;
	while (word[i] && word[i] != sep)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**vec_words;
	int		words;
	int		x;
	int		i;

	if (!s)
		return (NULL);
	x = 0;
	i = 0;
	words = count_words(s, c);
	vec_words = (char **)malloc((words + 1) * sizeof(char *));
	if (!vec_words)
		return (NULL);
	while (x < words)
	{
		while (s[i] == c)
			i++;
		vec_words[x] = ft_substr(s, i, len_word(s + i, c));
		if (!vec_words[x])
			return (NULL);
		i += len_word(s + i, c);
		x++;
	}
	vec_words[words] = NULL;
	return (vec_words);
}

/*int main()
{
	char	**result;
	int	i = 0;

	char *test = "^^^1^^2a,^^^^3^^^^--h^^^^";
	result = ft_split(test, '^');
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/