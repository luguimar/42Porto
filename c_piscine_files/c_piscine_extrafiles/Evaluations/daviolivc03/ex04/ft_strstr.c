/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:34:20 by davioliv          #+#    #+#             */
/*   Updated: 2023/02/20 14:23:28 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		a = 0;
		while (str[i + a] == to_find[a] && to_find[a] != '\0')
		{
			if (to_find[a + 1] == '\0')
				return (&str[i]);
			a++;
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	c[] = "bomoladia";
	char	a[] = "diad";

	printf("%s", ft_strstr(c, a));
	return (0);
}*/
