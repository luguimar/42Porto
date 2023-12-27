/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:07:08 by gbertass          #+#    #+#             */
/*   Updated: 2023/02/20 19:47:30 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	x;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{	
		x = 0;
		if (str[i] == to_find[x])
		{
			while (str[i + x] != '\0' && str[i + x] == to_find[x])
			{
				if (to_find[x + 1] == '\0')
				{
					return (&str[i]);
				}
				x++;
			}
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "meu cerebro esta cansado de pensar!";
	char	to_find[] = "can";
	char *resultado;
	
	resultado = ft_strstr(str, to_find);
	printf("resultado de &str[i]: %s\n", resultado);
	printf("strtr de &str[i]: %s\n", strstr(str, to_find));
}
/*This function takes two strings s1 and s2 as an argument
nd finds the first occurrence of the sub-string s2 in the string s1
The process of matching does not include the
terminating null-characters(‘\0’), but function stops there*/
