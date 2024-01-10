/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:19:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:08:51 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			x = 0;
		if (s1[i] > s2[i])
		{
			x = 1;
			return (x);
		}
		if (s1[i] < s2[i])
		{
			x = -1;
			return (x);
		}
		i++;
	}
	return (x);
}
 int main(void)
 {
	int a;
 	a = ft_strcmp("Fernando", "fernando");
 	printf("%d",a);
 	return (0);
 }
// strcmp("Fernando","fernando"
