/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:10:46 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 14:56:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(void)
{
	char	str[] = "1234";
	char	str1[] = "";
	char    str2[] = "he5llo";
	
	printf("%i\n", ft_str_is_numeric(str));
	printf("%i\n", ft_str_is_numeric(str1));
	printf("%i\n", ft_str_is_numeric(str2));
	return (0);
}

