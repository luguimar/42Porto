/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:29:58 by jgomes-v          #+#    #+#             */
/*   Updated: 2023/02/13 10:18:44 by jgomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (str[i] >= 'A' && str[i] <= 'Z')
		{	
		str[i] += 32;
		}
	i++;
	}	
	return (str);
}
/*int	main(void)
{
	char teste1[20] = "ANBV";

	ft_strlowcase(teste1);	
}*/
