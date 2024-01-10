/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:25:58 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/13 10:18:29 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{	
			str[i] -= 32;
		}
		i++;
	}	
	return (str);
}
/*int	main(void)
{
	char teste1[20] = "abcdeft tou";

	printf("%s",ft_strupcase(teste1));	
}*/	
