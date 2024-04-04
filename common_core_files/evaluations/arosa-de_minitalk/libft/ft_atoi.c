/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:53:04 by arosa-de          #+#    #+#             */
/*   Updated: 2022/12/17 01:04:01 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Convert a string to a integer
#include "libft.h"

int	ft_atoi(const char *s)
{
	int	count;
	int	index;
	int	result;

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
