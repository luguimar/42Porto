/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:26:34 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:25:51 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * Applies the function 'f' to each character of the string 's' to create a new
 * string. The new string is created using memory allocation with malloc
 * function, and its size is determined by the length of 's'.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	map = (char *)malloc(ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}

/*char char_plus(unsigned int i, char c) {
    return c + 1;
}

int main() {
    char *input = "hello";
    char *result = ft_strmapi(input, &char_plus);
    printf("Input string: %s\n", input);
    printf("Result string: %s\n", result);
    free(result);
    return 0;
}*/