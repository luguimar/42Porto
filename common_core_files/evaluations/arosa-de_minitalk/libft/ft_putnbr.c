/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:49:32 by arosa-de          #+#    #+#             */
/*   Updated: 2024/01/16 00:55:29 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIÇÃO: tot() trata os números negativos.
*/

/*
static int	ft_tot(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n != 0)
		i--;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
*/
/*
	DESCRIÇÃO: itoa() converte inteiro em string ASCII.
*/
/*
static char	*ft_itoa(int n)
{
	int		i;
	char	*c;

	i = ft_count(n);
	c = (char *) malloc((i + 2) * sizeof(char));
	if (!c)
		return (NULL);
	c[i + 1] = '\0';
	if (n == 0)
		c[i] = '0';
	if (n < 0)
		c[0] = '-';
	while (n != 0)
	{
		c[i--] = ft_tot(n % 10) + '0';
		n /= 10;
	}
	return (c);
}
*/
/*
	DESCRIÇÃO: putnbr() imprime os caracteres que representam os números.
*/

int	ft_putnbr(int n, int fd)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	free(s);
	return (i);
}
