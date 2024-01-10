/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:19:43 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/19 17:17:43 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	car;
	char	*s;
	int		size;

	size = ft_strlen(str);
	car = c;
	s = (char *)str;
	while (size >= 0)
	{
		if (s[size] == car)
		{
			return (s + size);
		}
		size --;
	}
	return (NULL);
}
