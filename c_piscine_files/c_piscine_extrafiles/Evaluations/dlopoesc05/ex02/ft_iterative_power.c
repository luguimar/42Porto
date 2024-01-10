/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:39:41 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/20 11:44:05 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
	{
		return (0);
	}
	while (power > 0)
	{
		res *= nb;
		--power;
	}
	return (res);
}
/*
int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 1;
	printf("%d\n", ft_iterative_power(nb, power));
	return (0);
}
*/
