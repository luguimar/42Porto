/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:43:07 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/20 13:28:44 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i <= nb / i)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		++i;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	next_prime = nb;
	while (!ft_is_prime(next_prime))
	{
		++next_prime;
	}
	return (next_prime);
}
/*
int	main(void)
{
	int	nb;

	nb = 14;
	printf("%d\n", ft_find_next_prime(nb));
	return (0);
}
*/
