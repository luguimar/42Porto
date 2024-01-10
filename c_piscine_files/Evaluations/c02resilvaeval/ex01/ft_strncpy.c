/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:01 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:35:36 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0' && i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "LaEleee";
	char	dest[] = "#########";
	unsigned	n = 9;

	printf("Antes\nsrc: %s\ndest: %s\n\n", src, dest);
	ft_strncpy(dest, src, n);
	printf("Depois\nsrc: %s\ndest: %s\n", src, dest);
}
