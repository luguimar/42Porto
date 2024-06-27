/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:23:35 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/02 08:59:05 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME : ft_strdup --- Duplicate a string.
**
**SYNOPSIS: char *strdup(const char *s);
**
**DESCRIPTION : The ft_strdup() function returns a pointer to a new string which
**	is a duplicate of the string s. Memory for the new string is obtained
**	with malloc() and can be freed with free().
**
**PARAMETERS:	s: string to be copied to a pointer.
**
**RETURN VALUE : On success, the ft_strdup() function returns a pointer to the
**	duplicated string. It returns NULL if insufficient memory was available,
**	with ERRNO set to indicate the cause of the error.
**
**ERRORS: ENOMEM Insufficient memory available to allocate duplicate string.
**
**FUNTION: malloc()*/
char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == 0)
		return (0);
	ft_memcpy(dest, s, ft_strlen(s) + 1);
	return (dest);
}
/*
int	main(void)
{
	char	ptr[] = "coisa";
	char	*ver;

	ver = ft_strdup(ptr);
	while (*ver)
		write(1, ver++, 1);
	return (0);
}
*/
