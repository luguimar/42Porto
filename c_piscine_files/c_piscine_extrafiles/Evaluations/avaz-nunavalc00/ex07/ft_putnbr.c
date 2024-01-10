/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-nun <avaz-nun@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:16:11 by avaz-nun          #+#    #+#             */
/*   Updated: 2023/02/13 18:55:52 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;
	int		r;
	int		nb1;

	if (nb < 10)
	{
		c = nb + 48;
	}
	else
	{
		nb1 = nb / 10;
		ft_putnbr(nb1);
	}
	r = nb % 10;
	c = r + 48;
	write(1, &c, 1);
}
int	main()
{
	ft_putnbr(-42);
}
