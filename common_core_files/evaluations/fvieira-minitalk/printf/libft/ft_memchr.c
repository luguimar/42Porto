/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:35:19 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/19 15:19:28 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	signed char		car;
	size_t			i;

	str = (char *) s;
	car = c;
	i = 0;
	while (i < n)
	{
		if (*str == car)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}
