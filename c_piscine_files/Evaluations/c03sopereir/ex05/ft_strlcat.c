/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopereir <sopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:06:32 by sopereir          #+#    #+#             */
/*   Updated: 2023/02/15 14:22:58 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;

	i = 0;
	j = 0;
	dest_len = str_len(dest);
	if (size <= dest_len)
		return (size + str_len(src));
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < size - dest_len - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest_len + str_len(src));
}

int main()
{
	char dest[50]="mekie ";
	unsigned int n=ft_strlcat(dest,"tudo biene?",17);

	printf("%s\n%d\n",dest,n);
	return 0;
}

