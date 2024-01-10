/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:13:07 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 15:01:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	strlen_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (strlen_str(src));
}


int	main(void)
{
	char	dest[] = "Hello Beatriz";
	char	src[] = "World";
	unsigned int	size = 6;
	ft_strlcpy(dest, src, size); 
	printf("%i\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}

