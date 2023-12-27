/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:25:10 by cmarrama          #+#    #+#             */
/*   Updated: 2023/02/05 11:38:01 by cmarrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		main(void);

void	ft_aux(int x, int y, int j)
{
	int	i;

	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if ((i == 0 && j == 0) || (i == (x - 1) && i != 0
					&& (j == (y - 1) && j != 0)))
				ft_putchar('A');
			else if ((i > 0 && i < (x - 1)) && (j == 0 || j == (y - 1)))
				ft_putchar('B');
			else if ((i == 0 || i == (x - 1)) && (j > 0 && j < (y - 1)))
				ft_putchar('B');
			else if ((i == (x - 1) && j == 0) || (j == (y - 1) && i == 0))
				ft_putchar('C');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	rush(int x, int y)
{
	int	j;

	j = 0;
	if (x <= 0 || y <= 0)
		write(1, "ERROR: invalid input\n", 21);
	ft_aux(x, y, j);
}
