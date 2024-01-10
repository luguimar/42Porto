/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:22:16 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/12 19:25:38 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int     main(void)
{
        int    teste= ft_str_is_printable("abc");
        int    teste2=ft_str_is_printable("ABC");
        int    teste3=ft_str_is_printable("!@");
	int	teste4=ft_str_is_printable("");

        printf("%i",teste);
        printf("%i",teste2);
        printf("%i",teste3);
	printf("%i",teste4);
}*/
