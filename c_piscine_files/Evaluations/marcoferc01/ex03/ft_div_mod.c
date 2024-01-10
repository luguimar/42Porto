/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:41:07 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:19:11 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

 int	main(void)
 {
 	int	n1;
 	int	n2;
 	int	div;
 	int	mod;

 	n1 = 21;
 	n2 = 4;
 	printf("n1 = %d | n2 = %d\n", n1, n2);
 	ft_div_mod(n1, n2, &div, &mod);
 	printf("div = %d | mod = %d\n", div, mod);
 	return (0);
 }
