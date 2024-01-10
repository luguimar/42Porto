/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:55:22 by fvieira-          #+#    #+#             */
/*   Updated: 2023/05/11 15:55:26 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long long int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count ++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count ++;
	}
	return (count);
}

char	*transformer_str(char *str, int nb, int c_digits)
{
	str[c_digits--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		nb = 147483648;
	}
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[c_digits--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	c_digits;
	char		*str_num;
	long int	nb;

	nb = n;
	c_digits = count_digits(nb);
	str_num = (char *)malloc(sizeof(char) * (c_digits + 1));
	if (str_num == NULL)
		return (NULL);
	str_num = transformer_str(str_num, nb, c_digits);
	return (str_num);
}

// int main(void)
// {
// 	char *res = ft_itoa(-2147483648);
// 	printf("%s\n", res);
// 	return 0;
// }
