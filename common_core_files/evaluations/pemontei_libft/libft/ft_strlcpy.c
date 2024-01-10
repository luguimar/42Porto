/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:08:25 by pemontei          #+#    #+#             */
/*   Updated: 2023/04/12 20:12:33 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * strlcpy() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room.  Note that room for the NUL should
 * be included in size.  Also note that strlcpy() only operate on true
 * ''C'' strings. This means that src must be NUL-terminated.
 *
 * strlcpy() copies up to size - 1 characters from the string src to dst,
 * NUL-terminating the result if size is not 0.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dest, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	
	size_t	src_size2;
	
	char	*src2;
	
	char	*dest2;


	src2 = calloc(11, sizeof(char));
	dest2 = calloc(8, sizeof(char));
	src2 = "ahoi, bebr";
	src_size2 = ft_strlcpy(dest2, src2, 8);
	printf("src ft: %s\n", src2);
	printf("dest ft: %s\n", dest2);
	printf("src_size ft: %zu\n", src_size2);
	return(0);
}*/