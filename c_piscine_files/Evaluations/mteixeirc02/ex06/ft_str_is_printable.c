/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:04:51 by mteixeir          #+#    #+#             */
/*   Updated: 2023/02/20 17:03:36 by mteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 127))
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
        char    str[] = "\n";

        ft_str_is_printable(str);
        printf("%i", ft_str_is_printable(str));
        return(0);
}*/
