/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:21:20 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 14:55:14 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		else
		{
			i++;
		}
	}
	return (1);
}

int	main(void)
{
	char	str[] = "h4ii";
	char	str1[] = "123";
	char    str2[] = "hello";

	ft_str_is_alpha(str);
	printf("%i\n", ft_str_is_alpha(str));
	printf("%i\n", ft_str_is_alpha(str1));
	printf("%i\n", ft_str_is_alpha(str2));
	return (0);
}

