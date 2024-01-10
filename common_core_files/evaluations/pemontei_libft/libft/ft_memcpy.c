/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:05:22 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/11 00:10:58 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * The memcpy() function copies n bytes from memory area src to memory area dest.
 * If dest and src overlap, behavior is undefined. Applications in which dest and
 * src might overlap should use memmove(3) instead.
 * Returns the original value of dst.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = src;
	d = dest;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int main ()
{
   const char src[50] = "replacer text";
   char dest[50];
   strcpy(dest,"Test the memcpy!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);

   const char src2[50] = "ft replacer text";
   char dest2[50];
   strcpy(dest2,"Test the ft_memcpy!");
   printf("Before memcpy dest = %s\n", dest2);
   ft_memcpy(dest2, src2, strlen(src2)+1);
   printf("After ft_memcpy dest = %s\n", dest2);

   return(0);
}*/