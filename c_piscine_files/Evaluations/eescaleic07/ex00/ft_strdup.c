/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:12:45 by eescalei          #+#    #+#             */
/*   Updated: 2023/02/21 23:48:39 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i])
		i++;
	cpy = malloc(sizeof(src) * i);
	i = 0;
	if (cpy == '\0')
		return (0);
	else
	{
		while (src[i])
		{
			cpy[i] = src[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
}

#include <stdio.h>
int	main(void)
{
	char	c[] = "abcdef";
	printf("%s", ft_strdup(c));
	free(ft_strdup(c));
}
