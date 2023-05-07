/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:20:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/28 17:17:40 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlenght;
	char	*str;

	i = start;
	strlenght = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	while (s[i] != '\0' && strlenght < len)
	{
		i++;
		strlenght++;
	}
	i = start;
	str = malloc(sizeof(char) * strlenght + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, strlenght + 1);
	return (str);
}
