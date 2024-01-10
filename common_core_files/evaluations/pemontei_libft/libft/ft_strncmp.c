/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:57:13 by pemontei          #+#    #+#             */
/*   Updated: 2023/04/12 21:13:22 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while ((str1[i] == str2[i] && str1[i] != '\0') && i < (n - 1))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*int main ()
{
    int res;
    int ft_res;
    char s1[] = "Hello";
    char s2[] = "Helloworld";
    res = strncmp(s1, s2, 5);
    if(res > 0)
    {
        printf("orig strncmp: s2 is less than s1\n");
    }
    else if(res < 0)
    {
        printf("orig strncmp: s1 is less than s2\n");
    }
    else if (res == 0)
    {
        printf("orig strncmp: s1 is equal to s2\n");
    }
    ft_res = ft_strncmp(s1, s2, 5);
    if(ft_res > 0)
    {
        printf("ft_strncmp: s2 is less than s1\n");
    }
    else if(ft_res < 0)
    {
        printf("ft_strncmp: s1 is less than s2\n");
    }
    else if (ft_res == 0)
    {
        printf("ft_strncmp: s1 is equal to s2\n");
    }
    return 0;
}*/