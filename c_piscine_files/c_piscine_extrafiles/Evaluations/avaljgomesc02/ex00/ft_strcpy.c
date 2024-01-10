/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:56:39 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/12 18:54:47 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	a[20];
	char	b[];

	b = "Hello World";
	ft_strcpy(a, b);
	printf("%s\n%s", a, b);
}*/
