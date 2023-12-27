/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:50:40 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 16:54:59 by mteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			return (0);
		}
		else
			i++;
	}
	return (1);
}
/*
int     main(void)
{
        char    str[] = "adf";

        ft_str_is_lowercase(str);
        printf("%i", ft_str_is_lowercase(str));
        return(0);
}
*/
