/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:48:24 by dlopes-d          #+#    #+#             */
/*   Updated: 2023/02/19 15:07:37 by dlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	res;

	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	res = nb * ft_recursive_factorial(nb - 1);
	return (res);
}
/*
int     main(void)
{
        int     nb1 = 5;
        int     nb2 = 6;
        int     nb3 = 7;
        int     nb4 = -12;
        int     nb5 = 0;

        printf("%d! = %d\n", nb1, ft_recursive_factorial(nb1));
        printf("%d! = %d\n", nb2, ft_recursive_factorial(nb2));
        printf("%d! = %d\n", nb3, ft_recursive_factorial(nb3));         
        printf("%d! = %d\n", nb4, ft_recursive_factorial(nb4));         
        printf("%d! = %d\n", nb5, ft_recursive_factorial(nb5));         
        return (0);
}
*/
