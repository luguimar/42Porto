/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:36:03 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/22 22:01:52 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_matriz(int width, int height)
{
	char	**matriz;
	int		i;

	i = 0;
	matriz = malloc(sizeof(char *) * height);
	while (i <= width)
	{
		matriz[i] = malloc(sizeof(char) * width + 1);
		i++;
	}
	return (matriz);
}

void	fillmatrix(char *map, char **matriz, int height, int width)
{
	int	i;
	int	j;
	int	ii;

	i = 0;
	ii = 0;
	while (map[ii] != '\n')
		ii++;
	j = 0;
	while (j <= height)
	{
		i = 0;
		while (map[ii] != '\n')
		{
			matriz[j][i] = map[ii];
			ii++;
			i++;
		}
		matriz[j][width] = '\0';
		j++;
		ii++;
	}	
}
