/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:43:29 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:43:18 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z' && i == 0))
		{
			*str -= 32;
			i++;
		}
		else if ((*str >= 'A' && *str <= 'Z' && i > 0))
		{
			*str += 32;
		}
		else if ((*str < '0') || (*str > '9' && *str < 'A')
			|| (*str > 'Z' && *str < 'a') || (*str > 'z'))
		{
			i = 0;
		}
		else
			i++;
		str++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = "oLA, tUDO bEM? 42pALAVRAS qUARENTA-e-duAS; cinqUEnta+e+Um";

	ft_strcapitalize(string);
	printf("%s", string);
}
