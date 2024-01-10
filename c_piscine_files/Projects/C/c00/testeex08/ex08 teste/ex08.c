/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:22:39 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/12 21:57:47 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	n_max(char *str, int n);

int	string_to_int(char *str, int n)
{
	int	retornado;
	int	i;
	int	x;
	int	n_orig;

	n_orig = n;
	x = 1;
	i = 0;
	retornado = 0;
	while (n > 0)
	{
		if (i > 0 && i < n)
			x = x * 10;
		retornado = retornado + (str[n - 1] - 48) * x;
		n--;
		i++;
	}
	return (retornado);
}

void	imprime(char *str, int n)
{
	char	vec1[10];
	int		i;

	n_max(vec1, n);
	i = 0;
	while (str[i] < str[i + 1])
		i++;
	i++;
	if (i == n)
	{
		if (str[0] == vec1[0])
		{
			write(1, str, n);
		}
		else
		{
			write(1, str, n);
			write(1, ", ", 2);
		}
	}
}

int	n_max(char *str, int n)
{
	int	i;
	int	algmax;
	int	n_orig;

	n_orig = n;
	algmax = 9;
	i = n;
	str[n] = '\0';
	while (i > 0)
	{
		str[i - 1] = ((char)(algmax) + '0');
		algmax = algmax - 1;
		i--;
	}
	/* int	n_orig;

	n_orig = n;
	while(n > 0)
	{
		str[n - 1] = n + '0';
		n--;
	}*/
	n = string_to_int(str, n_orig);
	return (n);
}

void	increm_str(char *vec, int n)
{
	int	i;
	int	i_orig;

	i = n;
	i_orig = n;
	if (i > 0)
	{
		if (vec[i - 1] == '9')
		{
			vec[i - 1] = '0';
			increm_str(vec, i - 1);
		}
		else
		{
			vec[i - 1]++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	str[10];
	int		n_orig;
	int		nmax;
	int		numero;

	n_orig = n;
	while (n >= 0)
	{
		if (n == n_orig)
			str[n] = '\0';
		str[n - 1] = ((char) n - 1) + '0';
		n--;
	}
	/*printf("%s", str);*/
	numero = string_to_int(str, n_orig);
	printf("%d", numero);
	while (n < n_orig)
		n++;
	nmax = n_max(str, n);
	while (numero < nmax)
	{
		increm_str(str, n);
		numero = string_to_int(str, n_orig);
		imprime(str, n);
	}
	increm_str(str, n);
}

int	main(void)
{
	ft_print_combn(9);
	return (0);
}
