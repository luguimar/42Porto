/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:41:14 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:11:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	leng_src;
	int	leng_dest;
	int	i;

	i = 0;
	leng_dest = 0;
	leng_src = 0;
	while (src[leng_src])
	{
		leng_src++;
	}
	while (dest[leng_dest])
	{
		leng_dest++;
	}
	while (i < leng_src)
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
	ft_strcat(s1,s2);
	printf("%s",s1);	
	return (0);
}
