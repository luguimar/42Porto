/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:22:31 by luide-so          #+#    #+#             */
/*   Updated: 2023/02/20 18:20:39 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/* int	main(void)
{
	int i;

	i = -3;
	while (i <= 47)
	{
		printf(" Fibonacci %d\t->\t%d\n", i, ft_fibonacci(i));
		i++;
	}
	return (0);
} */
