/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:05:39 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/21 23:27:51 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fillvec(int *vec, int min, int range)
{
	int	i;

	i = 0;
	while (i < range)
	{
		vec[i] = min;
		min++;
		i++;
	}
}

int	*ft_range(int min, int max)
{
	int	range;
	int	*vec;

	range = max - min;
	vec = ((int *)malloc(sizeof(int) * range + 1));
	if (min >= max)
	{
		vec = NULL;
		return (0);
	}
	fillvec(vec, min, range);
	return (vec);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min = 3;
	int	max = 18;
	int	range = max - min;
	int	i;
	int	*vec = ft_range(min, max);

	i = 0;
	while (i < range)
	{
		printf("%d ", vec[i]);
		i++;
	}
}*/
