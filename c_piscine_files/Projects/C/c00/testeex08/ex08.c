/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:50:27 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/12 17:21:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	string_to_int(char *str, int n);
int	char_to_int(char ch);

void	imprime(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] < str[i + 1])
	{
		i++;
	}
	i++;
	if (i == n)
	{
		write(1, str, n);
	}
}

int	n_max(char *str, int n)
{
	int	n_orig;

	n_orig = n;
	while (n > 0)
	{
		str[n - 1] = '9';
		n--;
	}
	n = string_to_int(str, n_orig);
	return (n);
}

int	potencia(int x, int n)
{
	if (n == 0)
		return (1);
	else
		return (x * potencia(x, n - 1));
}

int	string_to_int(char *str, int n)
{
	int	retornado;
	int	n_orig;
	int	i;

	i = 0;
	n_orig = n;
	retornado = 0;
	while (n > 0)
	{
		retornado = retornado + (str[n - 1] - 48) * potencia(10, i);
		n--;
		i++;
	}
	return (retornado);
}

int	char_to_int(char ch)
{
	int	i;

	i = 0;
	if (ch <= '9' && ch >= '0')
		i = (int)ch - 48;
	return (i);
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

void	func_1(int n)
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
	numero = string_to_int(str, n_orig);
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

void	ft_print_combn(int n)
{
	if (n < 10 && n > 0)
		func_1(n);
	else
		write(1, "Erro! Maior que 9 ou menor que 1!", 33);
}

int	main(void)
{
	ft_print_combn(1);
	return (0);
}
