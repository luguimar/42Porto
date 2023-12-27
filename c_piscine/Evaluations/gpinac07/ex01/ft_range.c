/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:16:20 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 23:50:57 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*x;
	int	index;

	if (min >= max)
	{
		return (NULL);
	}	
	x = malloc(sizeof (*x) * (max - min));
	if (!x)
	{
		return (0);
	}
	index = 0;
	while (min < max)
	{
		x[index] = min;
		index++;
		min++;
	}
	return (x);
}

#include <stdio.h>

int	main(void)
{
	int min;
	int max;
	int i;
	int range;
	int	*vec;

	i = 0;
	min = 7;
	max = 13;
	range = max - min;
	vec = ft_range(min, max);
	while (i < range)
	{
		printf( "%d", vec[i]);
		i++;
	}
}
