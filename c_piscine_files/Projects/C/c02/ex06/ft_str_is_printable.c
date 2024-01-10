/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:58:36 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/12 13:20:07 by luguimar         ###   ########.fr       */
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

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[j] >= ' ' && str[j] <= '~')
			j++;
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
	char	str[] = "ABCDEFG";
	char	str1[] = "ABCDEFG\n";
	char	str2[] = "";

	printf("%d\n%d\n%d", ft_str_is_lowercase(str), 
	ft_str_is_lowercase(str1), ft_str_is_lowercase(str2));
}*/
