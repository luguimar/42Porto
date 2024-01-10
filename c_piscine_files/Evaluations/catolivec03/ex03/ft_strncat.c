/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catolive <catolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:27:03 by catolive          #+#    #+#             */
/*   Updated: 2023/02/14 11:34:03 by catolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[c] != '\0' && c < nb)
	{
		dest[c + i] = src[c];
		c++;
	}
	dest[i + c] = '\0';
	return (dest);
}
// int main(void)
// {
// 	char n[25] = "abc";
// 	char *n2 = "hjak";
// 	unsigned int n3 = 1;
// 	printf("%s\n", ft_strncat(n, n2, n3));
// }
