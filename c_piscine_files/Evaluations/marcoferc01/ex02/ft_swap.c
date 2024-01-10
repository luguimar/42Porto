/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:37:01 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:17:15 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}


int	main(void)
{
	int n1;
	int n2;

	n1 = 5;
	n2 = 9;
	printf("n1 = %d | n2 = %d\n", n1, n2);
	ft_swap(&n1, &n2);
	printf("n1 = %d | n2 = %d\n", n1, n2);

	return (0);
}

