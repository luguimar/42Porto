/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:55:12 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/10 10:07:14 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	c;
	int	i;

	i = 0;
	c = size;
	size--;
	while (i < c / 2)
	{
		a = tab[size - i];
		b = tab[i];
		tab[i] = a;
		tab[size - i] = b;
		i++;
	}
}
/*
int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};
	int	size = 5;

	ft_rev_int_tab(tab, size);
	printf("%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}*/
