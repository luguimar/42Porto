/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:13:14 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/21 20:33:01 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	ii;

	i = 0;
	while (dest[i] != '\0')
		i++;
	ii = 0;
	while (src[ii] != '\0')
	{
		dest[i] = src[ii];
		i++;
		ii++;
	}
	dest[i] = '\0';
	return (dest);
}

int	reslen(int size, char **strs, int sepsize)
{
	int	i;
	int	len;

	len = -sepsize;
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]) + sepsize;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		len;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		return (result);
	}
	len = reslen(size, strs, ft_strlen(sep));
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i < size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	result[len + 1] = '\0';
	return (result);
}
/*
int	main(int argc, char *argv[])
{
	printf("result: /%s/ - size: %d", ft_strjoin(3, argv, ", "), 3);
}*/
