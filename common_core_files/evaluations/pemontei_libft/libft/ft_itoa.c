/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:29:59 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:46:23 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	number_size(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int		number;
	char			*res;
	int				size;

	number = n;
	size = number_size(n);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		number = -number;
	}
	res[size] = '\0';
	while (size > 0 && res[size - 1] != '-')
	{
		res[size - 1] = number % 10 + '0';
		number = number / 10;
		size--;
	}
	return (res);
}
