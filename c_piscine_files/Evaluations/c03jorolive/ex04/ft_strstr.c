/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:29:47 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/15 16:34:58 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//finds the first occurrence of the substring needle in the string haystack.
//the terminating null bytes are not compared.
//RETURNS:
//if needle is an empty string haystack is returned
//returns a pointer to the beginning of the located substring
//returns null if the substring is not found
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (to_find[j] == str[i])
		{
			while (to_find[j] == str[i + j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(void)
{
	char str[] = "abcdefghargf";
	char str1[] = "ar";
	printf("%s", ft_strstr(str, str1));
}
