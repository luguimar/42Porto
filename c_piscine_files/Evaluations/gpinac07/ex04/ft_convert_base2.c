/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpina-do <gpina-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:01:07 by gpina-do          #+#    #+#             */
/*   Updated: 2023/02/23 03:59:38 by gpina-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);
int	check_base(char *base);

int	ft_length(long nb, int base_len)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		counter++;
	}
	while (nb > 0)
	{
		nb = nb / base_len;
		counter++;
	}
	return (counter);
}

void	convert_dec_to_base(long nb, char *base_to, char *final, int final_len)
{
	int	base_len;

	base_len = ft_strlen (base_to);
	final[final_len] = '\0';
	final_len--;
	if (nb == 0)
		final[0] = base_to[0];
	if (nb < 0)
	{
		final[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		final[final_len] = base_to[nb % base_len];
		nb = nb / base_len;
		final_len--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long		nb;
	int			final_len;
	int			base_len;
	char		*final;

	nb = ft_atoi_base(nbr, base_from);
	if (check_base(base_to) == 1 && check_base(base_from) == 1)
	{
		base_len = ft_strlen (base_to);
		final_len = ft_length(nb, base_len);
		final = malloc(sizeof(char) * final_len + 1);
		if (!final)
			return (0);
		convert_dec_to_base(nb, base_to, final, final_len);
		return (final);
	}
	return (0);
}
