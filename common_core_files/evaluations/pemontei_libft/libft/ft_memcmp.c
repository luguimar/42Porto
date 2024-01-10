/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:27:56 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 21:52:26 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*
 * The memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * Returns zero if the two strings are identical, otherwise returns the
 * difference between the first two differing bytes (treated as unsigned char
 * values, so that ‘\200’ is greater than ‘\0’, for example). Zero-length
 * strings are always identical. This behavior is not required by C and portable
 * code should only depend on the sign of the returned value.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*s1;
	unsigned const char	*s2;
	size_t				i;

	i = 0;
	s1 = (unsigned const char *)str1;
	s2 = (unsigned const char *)str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*int main ()
{
    int res;
    int ft_res;
    char s1[] = "Hello";
    char s2[] = "Helloworld";
    res = memcmp(s1, s2, 5);
    if(res > 0)
    {
        printf("orig memcmp: s2 is less than s1\n");
    }
    else if(res < 0)
    {
        printf("orig memcmp: s1 is less than s2\n");
    }
    else if (res == 0)
    {
        printf("orig memcmp: s1 is equal to s2\n");
    }
    ft_res = ft_memcmp(s1, s2, 5);
    if(ft_res > 0)
    {
        printf("ft_memcmp: s2 is less than s1\n");
    }
    else if(ft_res < 0)
    {
        printf("ft_memcmp: s1 is less than s2\n");
    }
    else if (ft_res == 0)
    {
        printf("ft_memcmp: s1 is equal to s2\n");
    }
    return 0;
}*/