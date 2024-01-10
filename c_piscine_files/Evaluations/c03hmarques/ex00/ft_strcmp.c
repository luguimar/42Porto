/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:48:27 by hmarques          #+#    #+#             */
/*   Updated: 2023/02/13 18:56:55 by hmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main()
{
	printf("%d", ft_strcmp("Ola", "Ola1"));
	printf("\n%d", ft_strcmp("Ola", "O"));
	printf("\n%d", ft_strcmp("O", "Ola"));
	printf("\n%d", ft_strcmp("Ola", "Ola"));
}
