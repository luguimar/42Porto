/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:39:11 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:05:30 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * The strrchr() function locates the last occurrence of c (converted to a
 * char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefore if c is ‘\0’, the
 * functions locate the terminating ‘\0’.
 */
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i--;
	}
	return (0);
}

/*int main ()
{
   const char str[] = "ret's.test.the.strrchr";
   const char ch = '.';
   char *p, *p2;
   p = strrchr(str, ch);
   printf("Orig strrchr: String delimiter from %c is: %s\n", ch, p);
   p2 = ft_strrchr(str, ch);
   printf("ft_strrchr: String delimiter from %c is: %s\n", ch, p2);
   return 0;
}*/