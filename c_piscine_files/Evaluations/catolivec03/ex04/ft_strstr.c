/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catolive <catolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:07:27 by catolive          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:13 by catolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
// int main(void)
// {
// 	char str[40] = "its hello me";
// 	char substr[40] = "hello";
// 	printf("%s", ft_strstr(str, substr));
// }