/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:32:52 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 03:59:13 by gpina-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

int	return_lenght(int size, char **strs, int size_sep)
{
	int	index;
	int	len;

	index = -1;
	len = size_sep * -1;
	while (++index < size)
		len += size_sep + ft_strlen(strs[index]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *) malloc (1);
		return (res);
	}
	index = -1;
	len = return_lenght(size, strs, ft_strlen(sep));
	res = malloc (sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	while (++index < size)
	{
		res = ft_strcpy(res, strs[index]);
		if (index + 1 < size)
			res = ft_strcpy(res, sep);
	}
	*res = '\0';
	return (res - len);
}
