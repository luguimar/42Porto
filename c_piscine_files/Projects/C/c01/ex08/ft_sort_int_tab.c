/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:28:02 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/10 09:59:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	int vec[] = {5, 6, 8, 4, 6, 5, 0, 67, 65};
	int size = 9;
	ft_sort_int_tab(vec, size);
	printf("%d %d %d %d %d %d %d %d %d", vec[0],
       	vec[1], vec[2], vec[3], vec[4], vec[5], vec[6], vec[7], vec[8]);
}*/
