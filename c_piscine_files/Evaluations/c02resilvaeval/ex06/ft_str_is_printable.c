/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:10:33 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:40:45 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if ((*str < ' ') || (*str > '~'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char	string[] = " ~";

	printf("%d", ft_str_is_printable(string));
}
