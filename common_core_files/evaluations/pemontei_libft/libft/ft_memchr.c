/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:59:48 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:09:04 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * The memchr() function locates the first occurrence of c (converted to an
 * unsigned char) in string s. Returns a pointer to the byte located, or NULL
 * if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int main ()
{
   const char str[] = "Let's.test.the.strchr";
   const char ch = '.';
   char *p, *p2;
   p = memchr(str, ch, strlen(str));
   printf("Orig strchr: String starting from %c is: %s\n", ch, p);
   p2 = ft_memchr(str, ch, strlen(str));
   printf("ft_strchr: String starting from %c is: %s\n", ch, p2);
   return 0;
}*/