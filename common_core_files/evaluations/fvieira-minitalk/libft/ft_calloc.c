/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:53:11 by fvieira-          #+#    #+#             */
/*   Updated: 2023/11/20 14:29:39 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*new_array;

	if (size == 0)
	{
		new_array = malloc(1);
		return (new_array);
	}
	new_array = malloc(nitems * size);
	if (new_array == NULL)
		return (NULL);
	ft_bzero(new_array, size * nitems);
	return (new_array);
}
