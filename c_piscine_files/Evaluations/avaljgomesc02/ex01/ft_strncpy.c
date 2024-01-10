/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:32:49 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/13 13:44:30 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
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

/*int	main(void)
{
	char	a[] = "Hello";
	char	b[20];
	unsigned int	n;

	n = 2;
	ft_strncpy(b, a, n);
	printf("%s\n%s", a, b);
}*/
