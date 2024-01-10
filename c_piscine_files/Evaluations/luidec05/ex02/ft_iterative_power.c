/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:01:46 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/21 12:20:05 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	if (power < 0)
		return (0);
	nbr = 1;
	while (power-- > 0)
		nbr *= nb;
	return (nbr);
}

 int	main(void)
{
	int i;
    int j;
    int k = 8;

	i = -4;
	while (i <= k)
	{
        j = -1;
        while (j <= k)
        {
		    printf("%d elevado a %d ->\t%d\n", i, j, ft_iterative_power(i, j));
            j++;
        }
		i++;
	}
	return (0);
} 
