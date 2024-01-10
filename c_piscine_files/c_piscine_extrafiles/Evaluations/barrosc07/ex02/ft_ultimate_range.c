/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:30:58 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/21 15:12:33 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*vec;

	i = 0;
	vec = (int *)malloc(sizeof(int) * (max - min) + 1);
	if (min >= max)
	{
		vec = NULL;
		return (0);
	}
	if (min < max)
	{
		while (min < max)
		{
			vec[i] = min;
			min++;
			i++;
		}
		*range = vec;
		return (i);
	}
	else
		return (-1);
}
/*
int	main(void)
{
	
}*/
