/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:24:23 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/17 16:42:22 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	char	*str;
	int		size;

	str = (char *) s;
	size = ft_strlen(str);
	new_str = (char *) malloc(sizeof(char) * size + 1);
	if (new_str == NULL)
		return (0);
	new_str = ft_strcpy(new_str, str);
	return (new_str);
}
