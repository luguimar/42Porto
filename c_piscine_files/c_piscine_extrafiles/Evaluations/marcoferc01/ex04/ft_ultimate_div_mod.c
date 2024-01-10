/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:43:32 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:20:07 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b != 0)
	{
		temp = *a;
		*a = *a / *b;
		*b = temp % *b;
	}
}

 int	main(void)
 {
 	int	n1;
 	int	n2;

 	n1 = 21;
 	n2 = 4;
 	printf("n1 = %d | n2 = %d\n", n1, n2);
 	ft_ultimate_div_mod(&n1, &n2);
 	printf("n1 = %d | n2 = %d\n", n1, n2);
 	return (0);
 }
