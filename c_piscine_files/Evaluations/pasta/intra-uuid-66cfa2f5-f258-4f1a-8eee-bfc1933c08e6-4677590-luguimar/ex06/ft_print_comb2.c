/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:30:20 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/05 16:34:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*number_to_string(int x, char *str)
{
	if (x >= 0 && x < 100)
	{
		if (x / 10 < 1)
		{
			str[0] = '0';
			str[1] = x + '0';
		}
		else
		{
			str[0] = x / 10 + '0';
			str[1] = x % 10 + '0';
		}
	}
	return (str);
}

void	ft_print_comb2(void)
{
	int		x;
	int		y;
	char	str[2];

	x = 0;
	y = 0;
	while (x <= 99)
	{
		y = 0;
		while (y <= 99)
		{
			if (x < y)
			{
				if (x != 0 || y != 1)
					write(1, " ", 1);
				write(1, number_to_string(x, str), 2);
				write(1, " ", 1);
				write(1, number_to_string(y, str), 2);
				if (x != 98 || y != 99)
					write(1, ",", 1);
			}
			y++;
		}
		x++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
