/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:29:16 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/02/14 18:10:15 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	x;

	x = 0;
	i = 0;
	while ((s1[i] && i < n) || (s2[i] && i < n))
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
 	a = ft_strncmp("ferNando", "fernandw", 1);
 	printf("%d ",a);
 	return (0);
 }
