/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:01:03 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/19 22:41:30 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int nb)
{
	char	nnb;

	nnb = ((char) nb + '0');
	write (1, &nnb, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb / 10 == 0)
		ft_putchar(nb);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10);
	}
}

int	main(void)
{
	ft_putnbr(-1483648);
	return (0);
}
