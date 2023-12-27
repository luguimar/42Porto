/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:00:05 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:25:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


//////////////////// COMMENT !! ////////////////////
#include <stdio.h>

void	print_array(int *array, int size)
{
	int	i;
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void	ft_swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

//////////////////// COMMENT !! ////////////////////
void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	idx;
	int	flag_sort;

	flag_sort = 0;
	while (flag_sort == 0)
	{
		flag_sort = 1;
		idx = 0;
		while (idx < size - 1)
		{
			if (tab[idx] > tab[idx + 1])
			{
				flag_sort = 0;
				temp = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = temp;
			}
			idx++;
		}
	}
}

 int	main(void)
 {
 	int	tab1[] = {6, 2000, 3, 56, 234, 6, 3, 8, 5, 10};

 	print_array(tab1, 10);
 	ft_sort_int_tab(tab1, 10);
 	print_array(tab1, 10);
 	return (0);
 }
