/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:34:28 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:19:57 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

int	ft_size(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_d;
	unsigned int	size_s;

	i = 0;
	size_d = ft_size(dest);
	size_s = ft_size(src);
	if (size < 1)
		return (size_s);
	while (src[i] != '\0' && size_d < size - 1)
	{
		dest[size_d] = src[i];
		i++;
		size_d++;
	}
	dest[size_d] = '\0';
	if (size < size_d)
		return (size_s + size);
	else
		return (size_d + size_s);
}
 int main()
 {
 	char name1 [50] = "fernando";
 	char name2 [50] = "lucart";
 	unsigned int size;
 	size = 30;
 	printf("%d\n",ft_strlcat(name1,name2,size));

 	return 0;
 }
