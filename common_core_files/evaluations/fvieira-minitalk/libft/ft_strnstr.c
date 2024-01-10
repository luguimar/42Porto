/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:57:22 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/17 16:53:49 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*little1;
	char	*big1;

	little1 = (char *)little;
	big1 = (char *)big;
	i = 0;
	if (little1[0] == '\0')
		return (big1);
	while (big1[i] && i < len)
	{
		j = 0;
		while (big1[i + j] != '\0' && big1[i + j] == little1[j]
			&& (i + j < len))
		{
			if (little1[j + 1] == '\0')
				return (&big1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
