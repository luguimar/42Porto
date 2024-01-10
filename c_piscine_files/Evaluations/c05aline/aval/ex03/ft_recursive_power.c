/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:33:33 by alvieira          #+#    #+#             */
/*   Updated: 2023/02/19 17:53:48 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (0);
}

// int	main(void)
// {
// 	printf("retorno = %d", ft_recursive_power(-2, 5));
// }