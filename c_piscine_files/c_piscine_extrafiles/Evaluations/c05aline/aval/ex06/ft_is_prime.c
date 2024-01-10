/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:20:54 by alvieira          #+#    #+#             */
/*   Updated: 2023/02/19 18:57:30 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

 int	main()
 {
 	printf("%d", ft_is_prime(13));
 }
