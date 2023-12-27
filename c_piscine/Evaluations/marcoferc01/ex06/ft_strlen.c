/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:47:46 by marcofer          #+#    #+#             */
/*   Updated: 2023/02/11 20:22:04 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 #include <stdio.h>

void	ft_put_str(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

 int	main(void)
 {
 	char	*str;
 	int		len;

 	str = "Twin Peaks";
 	len = ft_strlen(str);
 	printf("%d", len);
 	return (0);
 }
