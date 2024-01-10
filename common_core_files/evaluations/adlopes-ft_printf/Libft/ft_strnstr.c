/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopes- <adlopes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:34:13 by adlopes-          #+#    #+#             */
/*   Updated: 2023/08/18 21:54:13 by adlopes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*need;

	hay = (char *)haystack;
	need = (char *)needle;
	if (need[0] == '\0')
		return (hay);
	i = 0;
	while (hay[i] != '\0')
	{
		j = 0;
		if (hay[i] == need[0])
		{
			while (hay[i + j] == need[j] && \
				(j + i) < len && need[j] != '\0')
				j++;
			if (need[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (0);
}
