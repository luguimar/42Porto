/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:19:47 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:42:31 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'Z'))
		{
			*str = *str + 32;
		}
		str++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	ft_strlowcase(string);
	printf("%s", string);
}
