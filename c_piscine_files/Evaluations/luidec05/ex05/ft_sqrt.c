/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:03:01 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/21 12:22:03 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

 int	main(void)
{
	int i;

	i = -4;
	while (i <= 47)
	{
		printf(" Raiz quadrada de %d\t->\t%d\n", i, ft_sqrt(i));
		i++;
	}
	return (0);
}
