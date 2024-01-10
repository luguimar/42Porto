/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:21:45 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 20:06:12 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i <= n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest[] = "s";
	char	src[] = "lisson";
	unsigned int	n = 9;

	ft_strncpy(dest, src, n);
	printf("%s", dest);
	return (0);
}
