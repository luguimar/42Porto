/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:34:43 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/12 19:39:29 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	ft_lowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] += 32;
		i++;
	}
	return (*str);
}

int	ft_check(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_lowcase(str);
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[i] -= 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z' && ft_check(str[i - 1]) == 0)
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
