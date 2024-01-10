/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertass <gbertass@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:34:11 by gbertass          #+#    #+#             */
/*   Updated: 2023/02/20 19:42:21 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	answer;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	answer = s1[i] - s2[i];
	return (answer);
}

int	main(void)
{
	char	s1[] = "me sinto cansada";
	char	s2[] = "hoje passei";
	char	test1[] = "me sinto cansada";
	char	test2[] = "hoje passei";
	int 	 result;
	
	result = ft_strcmp(s1, s2);
	printf("resultado e: %d\n", result);
	result = strcmp(test1, test2);
	printf("resultado e: %d\n", result);
}

// strcmp, strncmp - compares two strings character by character 
//if the strings are equal, the function returns 0.
// >0 if the first non matching char in str1 is greater(in ascii) than that str2
// <0 if the fist non matching char in str1 is lower in ascii than taht of str2
