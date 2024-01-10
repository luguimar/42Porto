/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:44:36 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:23:26 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		temp;
	int		idx;

	idx = 0;
	while (idx <= size / 2)
	{
		temp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size - 1 - idx] = temp;
		idx++;
	}
}

 int	main(void)
 {
 	int		tab1[] = {1, 2, 3, 4, 5};
 	int		idx;
 	int		size;

 	size = 5;
 	ft_rev_int_tab(tab1, size);
 	idx = 0;
 	while (idx < size)
 	{
 		printf("%d, ", tab1[idx]);
 		idx++;
 	}
 	return (0);
 }
