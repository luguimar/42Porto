/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:20:13 by alvieira          #+#    #+#             */
/*   Updated: 2023/02/19 18:52:10 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

 int	main(void)
 {
 	printf("retorno = %d\n", ft_recursive_factorial(5));
 }
