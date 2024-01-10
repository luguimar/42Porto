/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:01:09 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/20 15:20:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	passed_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;
	int	nbrb;

	nbr = 0;
	nbrb = 0;
	sign = 1;
	i = passed_spaces(str);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && nbrb == 0)
			sign = -sign;
		if ((str[i] < '0' || str[i] > '9') && nbrb == 1)
			return (nbr * sign);
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbr = nbr * 10;
			nbr = nbr + ((int) str[i] - '0');
			nbrb = 1;
		}
		i++;
	}
	return (nbr * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_atoi("  --- - 21474 83648"));
}*/
