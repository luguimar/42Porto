/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:42:21 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/21 11:32:29 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (nb > 0)
	{
		res *= nb;
		--nb;
	}
	return (res);
}

int	main(void)
{
	int	nb1 = 5;
	int 	nb2 = 6;
	int	nb3 = 7;
	int 	nb4 = -12;
	int	nb5 = 0;

	printf("%d! = %d\n", nb1, ft_iterative_factorial(nb1));
	printf("%d! = %d\n", nb2, ft_iterative_factorial(nb2));
	printf("%d! = %d\n", nb3, ft_iterative_factorial(nb3));		
	printf("%d! = %d\n", nb4, ft_iterative_factorial(nb4));		
	printf("%d! = %d\n", nb5, ft_iterative_factorial(nb5));		
	return (0);
}

