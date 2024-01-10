/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:59 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/23 19:36:06 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
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
	result[len] = '\0';
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	char *strs[3] = {"maria","jose","filipe"};
	char *array;
	array = ft_strjoin(3,strs," ");
	printf("%s",array);
	return 0;
}*/
