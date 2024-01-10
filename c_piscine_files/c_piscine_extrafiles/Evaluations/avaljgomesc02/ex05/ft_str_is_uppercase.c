/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:16:24 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/12 19:19:36 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0 ;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int     main(void)
{
        char    teste[3] ={'a', 'b', 'c'};
        char    teste2[3] = { 'A', 'B'};
        char    teste3[3] ={""};

        printf("%i",ft_str_is_uppercase(teste));
        printf("%i",ft_str_is_uppercase(teste2));
        printf("%i",ft_str_is_uppercase(teste3));
}*/
