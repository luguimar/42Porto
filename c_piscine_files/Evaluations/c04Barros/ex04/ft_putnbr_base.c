/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:23:20 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/19 22:44:15 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_error(char *base)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = ft_strlen (base);
	if (base[0] == '\0' || x == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[i] != base[j] && base[j] != '\0')
			j++;
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		baselen;
	int		i;
	long	n;

	i = 0;
	n = nbr;
	baselen = ft_strlen(base);
	if (ft_error(base) == 0)
		return ;
	if (nbr < 0)
	{
		n = nbr;
		n = -n;
		ft_putchar('-');
	}
	if (n < baselen)
		ft_putchar(base[n]);
	if (n >= baselen)
	{
		ft_putnbr_base(n / baselen, base);
		ft_putnbr_base(n % baselen, base);
	}
}

int main (void)
{
   ft_putnbr_base(2147, "01");
   write(1,"\n", 1);
   ft_putnbr_base(1256, "01");
 }
