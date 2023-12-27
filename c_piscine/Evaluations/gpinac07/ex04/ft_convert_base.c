/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:01:04 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 04:01:08 by gpina-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int	check_base(char *base)
{
	int	x;
	int	y;

	x = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[x] != '\0')
	{
		if (base[x] == '+' || base[x] == '-' || base[x] <= 32 || base[x] == 127)
			return (0);
		y = x - 1;
		while (y >= 0)
		{
			if (base[x] == base[y])
				return (0);
			y--;
		}
		x++;
	}
	return (1);
}

int	check_str(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int	convert_to_dec(char *str, char *base, int size)
{
	int	nb;
	int	power;
	int	index;

	nb = 0;
	power = 1;
	while (size >= 0)
	{
		index = 0;
		while (base[index] != '\0' && base[index] != str[size])
			index++;
		nb += index * power;
		power = power * ft_strlen(base);
		size--;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	sign;

	index = 0;
	sign = 1;
	if (check_base(base) == 0)
		return (0);
	if (str)
	{
		while (str[0] == ' ' || (str[0] >= 9 && str[0] <= 13))
			str++;
		while (str[0] == '-' || str[0] == '+')
		{
			if (str[0] == '-')
				sign = sign * -1;
			str++;
		}
		while (str[index] != '\0' && check_str(str[index], base) == 1)
			index++;
		return (sign * convert_to_dec(str, base, index - 1));
	}
	return (0);
}
