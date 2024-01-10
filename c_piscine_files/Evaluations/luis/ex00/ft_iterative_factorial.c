/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:54:05 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/20 18:34:34 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	x;

	x = nb - 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (x > 0)
	{
		nb = nb * x;
		x--;
	}
	return (nb);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_factorial(5));
}
