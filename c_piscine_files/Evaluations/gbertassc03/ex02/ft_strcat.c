/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:59:19 by gbertass          #+#    #+#             */
/*   Updated: 2023/02/20 19:45:46 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	main(void)
{
	char	src[] = "com esse teste";
	char	dest[100] = "estamos fazendo um bom trabalho";
	char	src1[] = "com esse teste";
	char	dest1[100] = "estamos fazendo um bom trabalho";
	
	ft_strcat(dest, src);
	printf("dest: %s\n", dest);
	strcat(dest1, src1);
	printf("dest: %s\n", dest1);
	return (0);
}
/*concatenates string2 to string1 and ends the 
function concatenates the destination string and the source string
and the result is stored in the destination string.*/
