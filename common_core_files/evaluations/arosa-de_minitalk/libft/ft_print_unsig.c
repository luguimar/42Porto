/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:48:08 by arosa-de          #+#    #+#             */
/*   Updated: 2023/04/15 06:03:09 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	unsig_number(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
	DESCRIÇÃO: print_unsig() imprime um número decimal sem sinal.
*/

int	ft_print_unsig(unsigned int n, int fd)
{
	unsigned int	d;
	int				length;
	char			*c;

	if (n == 0)
		return (write (fd, "0", 1));
	d = unsig_number(n);
	length = d;
	c = malloc((d + 1) * sizeof(char));
	c[d--] = '\0';
	if (n == 0)
		c[0] = '0';
	while (n != 0)
	{
		c[d--] = (n % 10) + 48;
		n = n / 10;
	}
	write(fd, c, length);
	free(c);
	return (length);
}
