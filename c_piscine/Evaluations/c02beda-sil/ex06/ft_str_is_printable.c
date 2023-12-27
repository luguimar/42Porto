/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beda-sil <beda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:26:28 by beda-sil          #+#    #+#             */
/*   Updated: 2023/02/15 14:58:14 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(void)
{
	char str[] = "Hello12\t3";
	char str1[] = "\0";
	ft_str_is_printable(str);
	printf ("%i\n", ft_str_is_printable(str));
	printf ("%i\n", ft_str_is_printable(str1));
	return (0);
}

