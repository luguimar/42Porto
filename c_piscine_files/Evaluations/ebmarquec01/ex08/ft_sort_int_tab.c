/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:58:51 by ebmarque          #+#    #+#             */
/*   Updated: 2023/02/08 13:22:33 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	power;
	int	swap;

	power = 1;
	while (power <= size)
	{
		i = 0;
		while (i <= size - 1)
		{
			if (tab[i] > tab[i + 1] && i != size - 1)
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		power++;
	}
}

/*int	main(void)
{
	int vetor[14] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	ft_sort_int_tab(vetor, 14);
	for (int i = 0; i < 14; i++)
	{
		printf("%d, ",vetor[i]);
	}
}*/