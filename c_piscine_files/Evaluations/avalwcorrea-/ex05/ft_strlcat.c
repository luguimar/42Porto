/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:04:33 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/14 21:09:43 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_lenght(char *str)
{
	unsigned int	i;

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
int	main(void)
{
	char	dest[] = "This is ";
	char	src[] = "a potentially long string";
	int	size = 30;

	printf("%s\n", dest);
	printf("%d\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);
}*/
