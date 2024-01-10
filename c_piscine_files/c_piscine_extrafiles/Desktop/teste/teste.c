/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:28 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/22 17:49:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	coordenates(char *map, int width, int height, char obs, int mapsize)
{
	int	max;

	i = 0;
	max = 0;
	while (i < mapsize)
	{
		if (map[i] == '\n' || map == obs)
			i = 0;
		if (i > max)
			max = i;
		i++;
	}
}
