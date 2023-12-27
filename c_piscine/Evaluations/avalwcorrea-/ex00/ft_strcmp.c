/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:47:10 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/11 17:33:36 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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
int	main(void)
{
	char	*s1 = "apple";
	char	*s2 = "apples";

	printf("My    : %d\n", ft_strcmp(s1, s2));
}*/
