/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:51:17 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/15 18:56:06 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int	modulo(long int x)
{
	if (x < 0)
		x = x * (-1);
	return (x);
}

int	alg_counter(long int x)
{
	int	count;

	count = 1;
	while (x / 10 > 0)
	{
		count++;
		x = x / 10;
	}
	return (count);
}

void	ft_putnbr(int nbr)
{
	int			is_negative;
	int			nbr_orig;
	int			i;
	long int	nbrl;
	char		str[11];

	nbrl = (long int) nbr;
	is_negative = 0;
	if (nbrl < 0)
		is_negative = 1;
	nbrl = modulo(nbrl);
	nbr_orig = alg_counter(nbrl);
	i = alg_counter(nbrl);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = ((char)(nbrl % 10)) + '0';
		nbrl = nbrl / 10;
		i--;
	}
	if (is_negative)
	{
		write(1, "-", 1);
	}
	write(1, str, nbr_orig);
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
}*/
