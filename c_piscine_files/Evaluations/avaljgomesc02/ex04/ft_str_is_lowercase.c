/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:12:55 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/12 19:15:54 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0 ;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char    teste[3] = "abc";
	char    teste2[3] = "ABC";
	char    teste3[3] = "";

	printf("%i",ft_str_is_lowercase(teste));
	printf("%i",ft_str_is_lowercase(teste2));
	printf("%i",ft_str_is_lowercase(teste3));
}*/
