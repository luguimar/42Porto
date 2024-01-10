/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:49:38 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/11 21:06:22 by luguimar         ###   ########.fr       */
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

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[j] >= '0' && str[j] <= '9')
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
	char	str[] = "12345";
	char	str1[] = "tata";
	char	str2[] = "123456 ";
	char	str3[] = "";

	printf("%d\n%d\n%d\n%d", ft_str_is_numeric(str), ft_str_is_numeric(str1)
	, ft_str_is_numeric(str2), ft_str_is_numeric(str3));
}*/
