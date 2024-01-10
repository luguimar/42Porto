/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:09:30 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/19 22:42:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] < 48 || str[i] > 58)
	{
		if (str[i] == 45)
			sign = -sign;
		else if ((str[i] != 45 && str[i] != 43 && str[i] != 32)
			&& !(str[i] > 8 && str[i] < 14))
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

#include <stdio.h>
int	main(void)
{
	char	str[] = " -\r+-\t+-+1234ab";
	int result = ft_atoi(str);
	printf("%d\n", result);
	return (0);
}
