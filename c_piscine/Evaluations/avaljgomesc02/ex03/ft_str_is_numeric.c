/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:24:14 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/13 15:08:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0 ;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	char	teste[4] = "1234";
	char	teste2[2] = "ol";
	char	teste3[] = "";

	printf("%i", ft_str_is_numeric(teste));
	printf("%i", ft_str_is_numeric(teste2));
	printf("%i", ft_str_is_numeric(teste3));
}
