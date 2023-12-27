/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:14:13 by resilva           #+#    #+#             */
/*   Updated: 2023/02/11 22:34:14 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char origem[] = "BIRL"; // o destino eh maior que a origem
	char dest[] = "aaaaaaa"; // qnd o destino eh menor, ocorre o estouro de buffer

	printf("dest antes: %s\n", dest);
	printf("origem antes: %s\n\n", origem);
	ft_strcpy(dest, origem);
	printf("dest depois: %s\n", dest);
        printf("origem depois: %s\n", origem);
}
