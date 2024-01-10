/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:05:51 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:44:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cont;
	unsigned int	i;

	cont = 0;
	i = 0;
	while (src[cont] != '\0')
		cont++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (cont);
}

#include <stdio.h>

int	main(void)
{
	char	orig[] = "BORAAA";
	char	dest[] = "aaaaaaaaaa";
	unsigned int	size;

	size = 4;
	printf("orig antes: %s\ndest antes: %s\nsize antes:%d\n\n", orig, dest, size);
	size = ft_strlcpy(dest, orig, size);
	printf("orig depois: %s\ndest depois: %s\nsize depois:%d", orig, dest, size);
	return (0);
}
