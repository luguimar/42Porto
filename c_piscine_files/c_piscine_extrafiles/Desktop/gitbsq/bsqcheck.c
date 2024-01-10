/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:01 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/22 21:39:58 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	bsqcheck(char **mat, char *symbols, int i, int j, int width, int height)
{
	
}

char	matrun(char **mat, char *symbols, int height, int width)
{
	int		i;
	int		j;
	int		ii;
	char	obs;

	i = 0;
	j = 0
	obs = symbols[1];
	while (j <= height)
	{
		while (i <= width)
		{
			if(mat[j][i] == obs)
			{
				i++;
			}
			else
			
		}
		j++;
	}

}
