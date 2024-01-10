/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:15:03 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 14:57:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(void)
{
	char str[] = "hello";
	char str1[] = "HELLO";
	char str2[] = "HELL4O";

	printf("%i\n",ft_str_is_uppercase(str));
	printf("%i\n", ft_str_is_uppercase(str1));
	printf("%i\n", ft_str_is_uppercase(str2));
	return (0);
}

