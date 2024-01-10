/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:24:30 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 23:59:45 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	*x;

	if (min >= max)
	{
		*range = NULL;
		return NULL;
	}
	index = 0;
	x = (int *)malloc(sizeof (*x) * (max - min));
	while (min < max)
	{
		x[index] = min;
		index++;
		min++;
	}
	*range = x;
	return (index);
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;

	
	if (argc == 3)
	{
		i = 0;
		while (i < argc)
		{
			printf("%s", argv[i]);
			i++;
		}
	}
}
