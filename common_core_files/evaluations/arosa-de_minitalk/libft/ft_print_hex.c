/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:46:32 by arosa-de          #+#    #+#             */
/*   Updated: 2023/04/15 06:02:26 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIÇÃO: print_hex() imprime um número em formato hexadecimal em minúsculas
	e minúsculas.
*/

int	ft_print_hex(unsigned int n, int c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex(n / 16, c);
		count += ft_print_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			count += ft_putchar((n + '0'));
		else
		{
			if (c == 'x')
				count += ft_putchar((n - 10 + 'a'));
			if (c == 'X')
				count += ft_putchar((n - 10 + 'A'));
		}
	}
	return (count);
}
