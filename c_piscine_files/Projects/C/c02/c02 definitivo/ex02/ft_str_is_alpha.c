/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:50:35 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/11 21:07:28 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[j] >= 'a' && str[j] <= 'z')
			|| (str[j] >= 'A' && str[j] <= 'Z'))
		{
			j++;
		}
		if (j == ft_strlen(str))
			return (1);
		else
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "12345";
	char	str1[] = "tata";
	char	str2[] = "cenasetal";
	char	str3[] = "cenas e tal";
	char	str4[] = "";
	char	str5[] = "cenas1";
	
	printf("%d\n%d\n%d\n%d\n%d\n%d", ft_str_is_alpha(str)
	, ft_str_is_alpha(str1), ft_str_is_alpha(str2), ft_str_is_alpha(str3)
	, ft_str_is_alpha(str4), ft_str_is_alpha(str5));
}*/
