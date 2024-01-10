/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:44:54 by gbertass          #+#    #+#             */
/*   Updated: 2023/02/20 19:46:23 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int main(void)
{
	char	dest[100] = "estamos cansados";
	char	src[] = "E ficando doidos pra xuxu";
	char	dest1[100] = "estamos cansados";
	char	src1[] = "E ficando doidos pra xuxu";
	unsigned int	nb;
	
	nb = 17;
	ft_strncat(dest, src, nb);
	printf("novo dest: %s\n", dest);
	strncat(dest1, src1, nb);
	printf("novo dest: %s\n", dest1);
	return (0);
}
/*dest-This is pointer to the destination array, 
which should contain a C string, and should be large enough 
to contain the concatenated resulting string which includes
the additional null-character.
src-This is the string to be appended.
n-This is the maximum number of characters to be appended*/
