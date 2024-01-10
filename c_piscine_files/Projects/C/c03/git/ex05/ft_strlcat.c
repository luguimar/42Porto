/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:55:01 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/14 20:57:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_lenght(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	lenghts;

	i = 0;
	lenghts = 0;
	dest_len = ft_lenght(dest);
	src_len = ft_lenght(src);
	if (size > dest_len)
		lenghts = dest_len + src_len;
	else
		lenghts = src_len + size;
	while (src[i] != '\0' && (dest_len + 1) < size)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (lenghts);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[] = "isto e ";
	char	src[] = "ganda string";
	unsigned int	size = 12;

	printf("%s\n", dest);
	printf("%d\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);
}*/
