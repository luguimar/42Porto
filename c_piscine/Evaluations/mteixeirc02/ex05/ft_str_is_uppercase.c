/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:59:29 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 16:59:51 by mteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
/*
int     main(void)
{
        char    str[] = "LOLPLOP";

        ft_str_is_uppercase(str);
        printf("%i", ft_str_is_uppercase(str));
        return(0);
}
*/
