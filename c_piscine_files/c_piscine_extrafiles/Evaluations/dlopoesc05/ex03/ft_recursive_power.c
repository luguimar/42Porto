/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:49:37 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/20 15:39:14 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power < 0)
	{
		return (0);
	}
	if (power == 0 || nb == 1)
	{
		return (1);
	}
	res = nb * ft_recursive_power(nb, power - 1);
	return (res);
}
/*
int	main(void)
{	
	int	nb;
	int	power;

	nb = 0;
	power = 0;
	printf("%d\n", ft_recursive_power(nb, power));
	return (0);
}
*/
