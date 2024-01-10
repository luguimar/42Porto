/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:54:19 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/21 15:28:19 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char const *s1, char const *s2)
{
	int	sizes1;
	int	sizes2;
	int	tsize;

	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	tsize = sizes1 + sizes2;
	return (tsize);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		size;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	size = ft_size(s1, s2);
	if (!str1 || !str2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (size)+1);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	ft_strlcat(new_str, str1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, str2, size + 1);
	return (new_str);
}

// int main(void)
// {
// 	char s1[50]="123";
// 	char s2[50]="andreia";
// 	char *dest = ft_strjoin(s1,s2);
// 	printf("%s",dest);
// 	return 0;
// }