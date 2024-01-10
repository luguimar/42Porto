/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:51:24 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:11:55 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	leng_dest;
	unsigned int	i;

	i = 0;
	leng_dest = 0;
	while (dest[leng_dest])
	{
		leng_dest++;
	}
	while (i < nb)
	{
		dest[leng_dest + i] = src[i];
		i++;
	}
	return (dest);
}
 int main()
 {
 	char s1 [] = "fernando";
 	char s2 [] = " lucart";
 	ft_strncat(s1,s2,3);
 	printf("%s",s1);	
 	return (0);
 }
