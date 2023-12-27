/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:38:52 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/21 12:19:01 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

 int main(void)
{
	int i;

	i = -3;
	while (i <= 35)
	{
		printf("Factorial de %d ->\t%d\n", i, ft_recursive_factorial(i));
		i++;
	}
	return (0);
}
