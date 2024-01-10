/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:19:18 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/21 12:18:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0)
		return (0);
	fact = 1;
	while (nb > 1)
		fact *= nb--;
	return (fact);
}

 int	main(void)
{
	int i;

	i = -3;
	while (i <= 35)
	{
		printf(" Factorial de %d ->\t%d\n", i, ft_iterative_factorial(i));
		i++;
	}
	return (0);
}
