/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:47:02 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/17 16:37:31 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	y;
	unsigned char	*name;
	size_t			i;

	y = (unsigned char)c;
	name = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*name = y;
		name++;
		i++;
	}
	return (s);
}
