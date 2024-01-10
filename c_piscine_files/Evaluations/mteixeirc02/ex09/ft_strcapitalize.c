/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:29 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 20:09:21 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[m] >= 'a' && str[m] <= 'z'))
		{
			str[m] -= 32;
			i++;
		}
		else if (i > 0 && (str[m] >= 'A' && str[m] <= 'Z'))
			str[m] += 32;
		else if ((str[m] < '0') || (str[m] > '9' && str[m] < 'A')
			|| (str[m] > 'Z' && str[m] < 'a') || (str[m] > 'z'))
			i = 0;
		else
			i++;
		m++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "call Me on+the line!55.";
	ft_strcapitalize(str);
	printf("%s", str);
	return(0);
}
