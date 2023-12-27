/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:23 by davioliv          #+#    #+#             */
/*   Updated: 2023/02/20 13:44:34 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] != s1[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	char	s1[] = "trata";
	char	s2[] = "tra";

	printf("%i\n", ft_strcmp(s1, s2));
	printf("%i\n", strcmp(s1, s2));
	return (0);
}*/
