/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:27:07 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 14:56:47 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		else
			i++;
	}
	return (1);
}

int	 main(void)
{
	char str[] = "beatriz";
	char str1[] = "BEATRIZ";
	char str2[] = "bre23ht";
	printf("%i\n", ft_str_is_lowercase(str));
	printf("%i\n", ft_str_is_lowercase(str1));
	printf("%i\n", ft_str_is_lowercase(str2));
	return (0);
}

