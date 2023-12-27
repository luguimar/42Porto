/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:27:23 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/12 17:59:35 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "cenas";
	char	s2[] = "cenase";

	printf("%d\n", ft_strcmp(s1, s2));
}*/
