/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:29:21 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:27:18 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * The strchr() function locates the first occurrence of c (converted to a
 * char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is ‘\0’, the
 * functions locate the terminating ‘\0’.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str && (unsigned char)c != *str)
		str++;
	if ((unsigned char)c == *str)
		return ((char *)str);
	return (0);
}

/*int main ()
{
   const char str[] = "Let's.test.the.strchr";
   const char ch = '.';
   char *p, *p2;
   p = strchr(str, ch);
   printf("Orig strchr: String starting from %c is: %s\n", ch, p);
   p2 = ft_strchr(str, ch);
   printf("ft_strchr: String starting from %c is: %s\n", ch, p2);
   return 0;
}*/