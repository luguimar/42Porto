/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:59:17 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/09 16:40:21 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	comparar(char *vec, char *vec1, int alg)
{
	int	i;

	i = 0;
	while (i < alg)
	{
		if (vec[i] != vec1[i])
			return (0);
		i++;
	}
	return (1);
}

void	incrementar(char *vec, int n)
{
	int	i;

	i = n;
	if (i > 0)
	{
		if (vec[i - 1] == '9')
		{
			vec[i - 1] = '0';
			incrementar(vec, i - 1);
		}
		else
		{
			vec[i - 1]++;
		}
	}
}

void	minmax(char *vec, char *vec1, int n)
{
	int	i;
	int	algmax;

	i = n;
	algmax = 9;
	vec[n] = '\0';
	vec1[n] = '\0';
	if (n == 1)
		write (1, "0, ", 3);
	while (i > 0)
	{
		vec[i - 1] = '0';
		vec1[i - 1] = ((char)(algmax) + '0');
		algmax--;
		i--;
	}
}

void	principal(char *vec, char *vec1, int n)
{
	int	i;

	minmax(vec, vec1, n);
	while (comparar(vec, vec1, n) == 0)
	{
		incrementar(vec, n);
		i = 0;
		while (vec[i] < vec[i + 1])
			i++;
		i++;
		if (vec[0] == vec1[0] && i == n)
			write (1, vec, n);
		else if (i == n)
		{
			write (1, vec, n);
			write (1, ", ", 2);
		}
	}
}

void	ft_print_combn(int n)
{
	char	vec[10];
	char	vec1[10];

	if (n < 1 || n > 9)
		write (1, "Error! Invalid Input", 20);
	else
		principal(vec, vec1, n);
}
/*
int	main(void)
{
	ft_print_combn(1);
	return (0);
}*/
