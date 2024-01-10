/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:17:42 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:38:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a') || (str[i] > 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = "0123456";
	char	string1[] = "abcdefghijklmnopqrstuvwxyz";
	char	string2[] = "";
	
	printf("%d\n", ft_str_is_lowercase(string));
	printf("%d\n", ft_str_is_lowercase(string1));
	printf("%d\n", ft_str_is_lowercase(string2));
	return (0);
}
