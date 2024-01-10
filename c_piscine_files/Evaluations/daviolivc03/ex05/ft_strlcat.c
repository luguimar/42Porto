/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:06:53 by davioliv          #+#    #+#             */
/*   Updated: 2023/02/22 12:07:26 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	k;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	k = i;
	while (src[a] != '\0' && i + 1 < size)
	{
		dest[i] = src[a];
		i++;
		a++;
	}
	if (size <= k)
		return (size + a);
	dest[i] = '\0';
	return (i);
}

int		main(void)
{
	char dest[20] = "123";
	char src[] = "4567890";
	unsigned int size = 10;
	unsigned int result;

	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
	result = ft_strlcat(dest, src, size);
	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);

	return (0);
}
