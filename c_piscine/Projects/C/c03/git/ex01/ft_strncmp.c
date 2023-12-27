/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:28:40 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/12 18:03:54 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char s1[] = "Hello";
	char s2[] = "Hello";
	int n = 5;

	printf("%d\n", strncmp(s1, s2, n));
	printf("%d\n", ft_strncmp(s1, s2, n));
}*/
