/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:33:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/05 18:08:51 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(char x, char y, char z)
{
	if (x == '7' && y == '8' && z == '9')
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, &z, 1);
	}
	else
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, &z, 1);
		write(1, ",", 2);
		write(1, " ", 2);
	}
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0';
	y = '0';
	z = '0';
	while (x <= '9')
	{
		y = '0';
		while (y <= '9')
		{
			z = '0';
			while (z <= '9')
			{
				if (x < y && y < z)
				{
					print_numbers(x, y, z);
				}
				z++;
			}
			y++;
		}
		x++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
