/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:53:04 by arosa-de          #+#    #+#             */
/*   Updated: 2024/01/18 01:11:05 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Convert a string to a integer
#include "libft.h"

long int	ft_atoi_long(const char *s)
{
	int			count;
	long int	index;
	long int	result;

	count = 0;
	index = 1;
	result = 0;
	while ((s[count] >= 9 && s[count] <= 13) || s[count] == 32)
		count++;
	if (s[count] == 45)
	{
		index *= -1;
		count++;
	}
	else if (s[count] == 43)
		count++;
	while (s[count] >= 48 && s[count] <= 57)
	{
		result = (s[count] - 48) + (result * 10);
		count++;
	}
	return (result * index);
}
