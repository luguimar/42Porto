/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:54:51 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/21 12:26:31 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = nb - 1;
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

 int	main(void)
{
	int i;

	i = -2;
	while (i <= 47)
	{
		printf("%d e' primo? \t->\t%d\n", i, ft_is_prime(i));
		i++;
	}
	return (0);
}
