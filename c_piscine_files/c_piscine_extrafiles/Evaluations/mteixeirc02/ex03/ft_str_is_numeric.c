/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:04:04 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:20 by mteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		return (0);
	}
	else
		i++;
	return (1);
}
/*
int     main(void)
{
        char    str[] = "+";

        ft_str_is_numeric(str);
        printf("%i", ft_str_is_numeric(str));
        return(0);
}*/
