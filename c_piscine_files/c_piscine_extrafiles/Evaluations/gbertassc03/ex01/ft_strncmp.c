/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:44:47 by gbertass          #+#    #+#             */
/*   Updated: 2023/02/20 19:43:08 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	answer;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	answer = s1[i] - s2[i];
	return (answer);
}

int	main(void)
{
	int	n;
	int	resultado;
	char	s1[] = "teste1";
	char	s2[] = "teste2";
	
	n = 5;
	resultado = ft_strncmp(s1, s2, n);
	printf("s1: %s\n s2: %s\n e n: %d\n", s1, s2, resultado);
	resultado = strncmp(s1, s2, n);
	printf("s1: %s\n s2: %s\n e n: %d\n", s1, s2, resultado);
}

/*str1− This is the first string to be compared
str2- This is the second string to be compared.
n- The maximum number of characters to be compared.*/
