/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucktions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:54:22 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/22 20:24:32 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	theight(char *str)
{
	int	alg;
	int	i;
	int	result;

	result = 0;
	alg = 0;
	i = 0;
	while (str[alg] != '\n')
		alg++;
	alg = alg - 3;
	while (i < alg)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

char	*threechars(char *map, char *three)
{
	int		i;
	int		alg;

	alg = 0;
	while (map[alg] != '\n')
		alg++;
	i = alg - 3;
	alg = 0;
	while (map[i] != '\n')
	{
		three[alg] = map[i];
		alg++;
		i++;
	}
	return (three);
}

int	twidth(char *str)
{
	int	i;
	int	ii;

	i = 0;
	while (str[i] != '\n')
		i++;
	ii = i + 1;
	i = i + 2;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i - ii);
}

void	writearray(char *map, char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < theight(map))
	{
		j = 0;
		while (j < twidth(map))
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
