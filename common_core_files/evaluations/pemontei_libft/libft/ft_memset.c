/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:09:10 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:05:59 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>

/*
 * The memset() function writes len bytes of value c (converted to an unsigned
 * char) to the string b. Returns its first argument.
 */
void	*ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)str)[n - 1] = c;
		n--;
	}
	return (str);
}

/*int main()
{
	char str[50];

	printf("ft_memset: %s", ft_memset(str, 'b', 5));
	printf("\nOriginal memset: %s", memset(str, 'b', 5));
}*/