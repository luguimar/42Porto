/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:47:33 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/23 21:06:29 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		strsize;
	char	*newstr;

	strsize = ft_strlen(src);
	newstr = (char *)malloc(sizeof(*newstr) * strsize + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	newstr[strsize] = '\0';
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	return (newstr);
}

#include <stdio.h>
int	main(void)
{
	char	c[] = "abcdefghijk";
	printf("%s", ft_strdup(c));
	free(ft_strdup(c));
}
