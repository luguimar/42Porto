/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:56:43 by davioliv          #+#    #+#             */
/*   Updated: 2023/02/20 13:55:02 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
		i++;
	while (src[a] != '\0' && a < nb)
	{
		dest[i] = src[a];
		a++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	c[50] = "teste";
	char	a[] = "festa";
	unsigned int	b = 7;

	printf("%s\n", ft_strncat(c, a, b));
	printf("%s\n", strncat(c, a, b));
	return (0);
}*/
