/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:44:46 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:21:06 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 #include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

 int	main(void)
 {
 	char	*str;

 	str = "Twin Peaks";
 	ft_putstr(str);
 	return (0);
 }
