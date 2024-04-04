/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:21:15 by arosa-de          #+#    #+#             */
/*   Updated: 2024/01/18 01:54:04 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Locates the first occurrence of 'c' in the string pointed to by 's'
//The terminating null character is considered to be part of the string
//therefore if 'c' is '\0', locates the terminating '\0'
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
