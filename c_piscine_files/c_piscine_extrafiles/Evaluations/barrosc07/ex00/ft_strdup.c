/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:24 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/23 22:23:56 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		strsize;
	char	*newstr;

	strsize = ft_strlen(src);
	newstr = (char *)malloc(sizeof(*newstr) * strsize + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	newstr[strsize] = '\0';
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	return (newstr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	c[] = "abcdef";
	printf("%s", ft_strdup(c));
	free(ft_strdup(c));
}*/
