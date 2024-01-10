/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenezes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:14:26 by amenezes          #+#    #+#             */
/*   Updated: 2023/02/14 19:13:51 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ldt;
	unsigned int	lsr;
	unsigned int	lenghts;

	i = 0;
	lenghts = 0;
	ldt = ft_strlen(dest);
	lsr = ft_strlen(src);
	if (size > ldt)
	{
		lenghts = ldt + lsr;
	}
	else
	{
		lenghts = lsr + size;
	}
	while (src[i] != '\0' && (ldt + 1) < size)
	{
		dest[ldt] = src[i];
		i++;
		ldt++;
	}
	dest[ldt] = '\0';
	return (lenghts);
}

#include <stdio.h>

int	main(void)
{
	char	src[] = "42";
	char	dest[20] = "Ola meu chapa ";
	unsigned int	size = 20;

	size = ft_strlcat(dest, src, size);
	printf("size: %d\ndest: %s", size, dest);
	return (0);
}
