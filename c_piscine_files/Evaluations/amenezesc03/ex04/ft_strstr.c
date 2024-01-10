/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenezes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 00:13:15 by amenezes          #+#    #+#             */
/*   Updated: 2023/02/14 19:12:40 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (to_find[y] == '\0')
	{
		return (str);
	}
	while (str[x] != '\0')
	{
		while (str[x + y] == to_find[y] && str[x + y] != '\0')
		{
			y++;
		}
		if (to_find[y] == '\0')
		{
			return (str + x);
		}
		x++;
		y = 0;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "ISSO AI";
	char	find[] = "";
	char    s11[] = "EU QUERO PANCADAO";
        char    find1[] = "PANCADO";


	printf("falsa: %s\n", ft_strstr(s1, find));
	printf("original: %s", strstr(s11, find1));
	return (0);
}
