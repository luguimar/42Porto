/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaz-nun <avaz-nun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:41:55 by avaz-nun          #+#    #+#             */
/*   Updated: 2023/02/13 18:52:13 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_res(char n1, char n2, char n3)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0';
	n2 = '0';
	n3 = '0';
	while (n1 <= '7')
	{
		n2 = n1 + 1;
		while (n2 <= '9')
		{
			n3 = n2 + 1;
			while (n3 <= '9')
			{
				print_res(n1, n2, n3);
				n3++;
			}
			n2++;
		}
		n2 = '0';
		n1++;
	}
}

int main()
{
	ft_print_comb();
}
