/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:10:03 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/13 13:01:00 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;	

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 64 || (str[i] > 90 && str[i] < 96) || str[i] > 123)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char	teste[4] = "ab!v";

	printf("%i",ft_str_is_alpha(teste));
}*/
