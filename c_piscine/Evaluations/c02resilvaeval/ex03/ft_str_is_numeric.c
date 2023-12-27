/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:27:52 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:37:22 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0') || (*str > '9'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = "Hellooo";
	char	string1[] = "0123456";
	char	string2[] = "";

	printf("%d\n", ft_str_is_numeric(string));
	printf("%d\n", ft_str_is_numeric(string1));
	printf("%d\n", ft_str_is_numeric(string2));
}
