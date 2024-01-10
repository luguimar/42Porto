/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:40:23 by davioliv          #+#    #+#             */
/*   Updated: 2023/02/22 12:05:45 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && i < n)
	{
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	s1[] = "trata";
	char	s2[] = "treta";
	unsigned int	a;

	a = 3;
	printf("%i\n", ft_strncmp(s1, s2, a));
	printf("%i\n", strncmp(s1, s2, a));
	return (0);
}
