/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:41 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:36:32 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'A') || (*str > 'Z' && *str < 'a') || (*str > 'z'))
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
	char	string[] = "aAbEDeeeR";
	char	string1[] = ".;.;.;";
	char	string2[] = "";
	
	printf("%d\n", ft_str_is_alpha(string));
	printf("%d\n", ft_str_is_alpha(string1));
	printf("%d\n", ft_str_is_alpha(string2));
}
