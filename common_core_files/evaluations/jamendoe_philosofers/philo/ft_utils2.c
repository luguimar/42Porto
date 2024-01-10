/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:37:05 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./philo.h"

long long	ft_atoll(const char *str)
{
	long long	res;
	int			signal;
	int			i;

	res = 0;
	signal = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i += 1;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i += 1;
	}
	return (res * signal);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	unsigned char	*nptrp;
	int				sign;
	int				value;

	nptrp = (unsigned char *) nptr;
	value = 0;
	sign = 1;
	while ((*nptrp >= 9 && *nptrp <= 13) || (*nptrp == 32))
		nptrp++;
	if (*nptrp == 45 || *nptrp == 43)
	{
		if (*nptrp == 45)
			sign *= -1;
		nptrp++;
	}
	while (*nptrp >= 48 && *nptrp <= 57)
	{
		value *= 10;
		value += *nptrp - 48;
		nptrp++;
	}
	return (value * sign);
}
