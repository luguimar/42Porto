/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira- <fvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:59:07 by fvieira-          #+#    #+#             */
/*   Updated: 2023/05/11 15:07:01 by fvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*substr;

	j = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (j < len)
	{
		substr[j] = s[start];
		start ++;
		j ++;
	}
	substr[j] = '\0';
	return (substr);
}
// int main(void)
// {
// 	char *substr;
// 	substr = ft_substr("hora", 45896215763, 0);
// 	printf("%s", substr);
// 	return 0;
// }
