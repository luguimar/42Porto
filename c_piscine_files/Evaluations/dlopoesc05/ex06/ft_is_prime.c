/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:26:58 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/20 16:30:35 by dlopes-d         ###   ########.fr       */
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
/*
int	main(void)
{
	int	nb;

	nb = 6;
	printf("%d\n", ft_is_prime(nb));
	return (0);
}
*/
