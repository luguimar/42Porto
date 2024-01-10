/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:14:17 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 21:51:13 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * strlcat() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room.  Note that room for the NUL should be
 * included in size. Also note that strlcat() only operate on true ''C''
 * strings. This means that both src and dst() must be NUL-terminated.
 *
 * strlcat() appends string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 characters.
 * It will then NUL-terminate, unless size is 0 or the original dst string
 * was longer than size (in practice this should not happen as it means that
 * either size is incorrect or that dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (len_d >= size)
		return (size + len_s);
	while (src[i] != '\0' && i < (size - len_d - 1))
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}

/*int		main(void)
{
	char dest[8] = "123";
	char src[] = "4567890";
	unsigned int size = 8;
	unsigned int result;

	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
	result = ft_strlcat(dest, src, size);
	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);

	return (0);
}*/