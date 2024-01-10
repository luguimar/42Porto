/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:57:35 by fvieira-          #+#    #+#             */
/*   Updated: 2023/05/11 15:57:37 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	row_number(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j++;
		}
		i++;
	}
	return (j);
}

char	**str_dist(char const *s, char c, char **split_str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < row_number(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != '\0' && s[end] != c)
			end++;
		split_str[i] = (char *)malloc((end - start + 1) * sizeof(char));
		if (split_str == NULL)
			return (NULL);
		ft_strlcpy(split_str[i], s + start, end - start + 1);
		i++;
	}
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;

	split_str = (char **)malloc((row_number(s, c) + 1) * sizeof(char *));
	if (split_str == NULL)
		return (NULL);
	split_str = str_dist(s, c, split_str);
	split_str[row_number(s, c)] = NULL;
	return (split_str);
}

// int main(void)
// {
//     char *s = "lorem ipsum dolor sit amet";
//     char **split = ft_split(s, ' ');
//     int x = 0;
//     while (split[x] != NULL)
//     {
//         printf("%s\n", split[x]);
//         x++;
//     }
//     return 0;
// }