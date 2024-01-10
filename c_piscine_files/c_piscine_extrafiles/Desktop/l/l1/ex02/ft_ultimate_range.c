/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:41:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/23 18:41:55 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*vec;
	int		i;

	i = 0;
	if (min >= max)
	{
		vec = NULL;
		return (0);
	}
	vec = malloc(sizeof(int) * (max - min));
	if (vec == NULL)
		return (-1);
	while (min < max)
	{
		vec[i] = min;
		i++;
		min++;
	}
	*range = vec;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int i;
	int *vec;
	int min;
	int max;
	int size;

	min = -100;
	max = 100;
	size = ft_ultimate_range(&vec, min, max);
	if (vec != NULL)
	{
		i = 0;
		while (i < max - min)
		{
			printf("%d\n", vec[i]);
			i++;
		}
	}
	else
		printf("Error");
}*/
