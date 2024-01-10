/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:25:20 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/18 16:36:12 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nb_orig;

	nb_orig = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb_orig);
	while (power > 1)
	{
		nb = nb * nb_orig;
		power--;
	}
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d",ft_iterative_power(0, 0));
}*/
