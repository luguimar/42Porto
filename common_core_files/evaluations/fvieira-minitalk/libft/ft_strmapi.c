/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:41:00 by fvieira-          #+#    #+#             */
/*   Updated: 2023/04/28 15:37:10 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*iter_str;
	int		size_s;
	int		i;

	i = 0;
	size_s = ft_strlen(s);
	iter_str = (char *)malloc(size_s + 1);
	if (!iter_str)
		return (NULL);
	while (s[i] != '\0')
	{
		iter_str[i] = f(i, s[i]);
		i++;
	}
	iter_str[i] = '\0';
	return (iter_str);
}
// int main()
// {
// 	char name[10]="ana";
// 	char *new;
// 	new = ft_strmapi(name, ft_strchar(1,"a"));
// 	printf("%s",new);
// 	return 0;
// }