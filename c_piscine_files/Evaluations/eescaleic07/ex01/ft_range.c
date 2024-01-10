/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:39:08 by eescalei          #+#    #+#             */
/*   Updated: 2023/02/21 23:52:42 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
		return ('\0');
	tab = malloc(sizeof(*tab) * (max - min));
	if (tab == NULL)
		return (0);
	else
	{
		while (i < (max - min))
		{
			tab[i] = min + i;
			i++;
		}
		return (tab);
	}
}

#include <stdlib.h>
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
}
