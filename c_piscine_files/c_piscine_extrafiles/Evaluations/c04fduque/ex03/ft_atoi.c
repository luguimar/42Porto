/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:43:07 by fduque-a          #+#    #+#             */
/*   Updated: 2023/02/21 11:02:03 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi2(char *str, int i, int m)
{
	int	aux;

	aux = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		aux = aux * 10 + str[i] - 48;
		i++;
	}
	if (m % 2 != 0)
		aux = aux * -1;
	return (aux);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (str[i] < '0' || str[i] > '9')
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				m++;
			i++;
		}
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)
			|| (str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	}
	return (ft_atoi2(str, i, m));
}

#include <stdio.h>

int	main(void)
{
	char	asd[30] = " 	  --+-+ --1231244721";

	printf("%d",ft_atoi(asd));
}
