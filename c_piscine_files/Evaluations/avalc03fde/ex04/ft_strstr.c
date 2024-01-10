/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:07:44 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:16:59 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<unistd.h>
#include<stdio.h>

int	ft_size(char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{	
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;

	size = 0;
	i = 0;
	j = 0;
	size = ft_size(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			x = i;
			while (str[x] == to_find[j] && j < size)
			{
				x++;
				j++;
				if (j == size)
					return (&str[i]);
			}	
		}
		i++;
	}
	return (NULL);
}

 int main(void)
 {	




 	printf("%s",ft_strstr("hi froguiiii hehe","frog"));
 	return (0);
 }
