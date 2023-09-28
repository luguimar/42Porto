/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:12:15 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/28 00:34:19 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rewire(char **aux, char **s, char **str)
{
	free(*s);
	free(*str);
	(*s) = (*aux);
	(*str) = NULL;
	(*aux) = NULL;
}

char	*ft_strjoin_arg_free(int strnbr, char *s, ...)
{
	va_list	arg;
	int	i;
	int	j;
	int	k;
	char	*str;
	char	*aux;

	va_start(arg, s);
	i = 1;
	while (++i <= strnbr)
	{
		j = -1;
		str = va_arg(arg, char *);
		aux = malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(str) + 1));
		if (!aux)
			return (NULL);
		while (s[++j] != '\0')
			aux[j] = s[j];
		k = -1;
		while (str[++k] != '\0')
			aux[j++] = str[k];
		aux[j] = '\0';
		rewire(&aux, &s, &str);
	}
	va_end(arg);
	return (s);
}
/*
int	main(void)
{
	char	*str;
	char	*str1 = malloc(10);
	char	*str2 = malloc(10);
	char    *str3 = malloc(10);
	char    *str4 = malloc(13);
	char    *str5 = malloc(10);
	char    *str6 = malloc(10);

	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = 'd';
	str1[4] = 'e';
	str1[5] = 'f';
	str1[6] = 'g';
	str1[7] = 'h';
	str1[8] = 'i';
	str1[9] = '\0';

	str2[0] = 'j';
	str2[1] = 'k';
	str2[2] = 'l';
	str2[3] = 'd';
	str2[4] = 'e';
	str2[5] = 'f';
	str2[6] = 'g';
	str2[7] = 'h';
	str2[8] = 'i';
	str2[9] = '\0';

	str3[0] = 'm';
	str3[1] = 'n';
	str3[2] = 'o';
	str3[3] = 'p';
	str3[4] = 'q';
	str3[5] = 'f';
	str3[6] = 'g';
	str3[7] = 'h';
	str3[8] = 'i';
	str3[9] = '\0';

	str4[0] = 'a';
	str4[1] = 'b';
	str4[2] = 'c';
	str4[3] = 'd';
	str4[4] = 'e';
	str4[5] = 'f';
	str4[6] = 'g';
	str4[7] = 'h';
	str4[8] = 'i';
	str4[9] = '\0';

	str5[0] = 'a';
	str5[1] = 'b';
	str5[2] = 'c';
	str5[3] = 'd';
	str5[4] = 'e';
	str5[5] = 'f';
	str5[6] = 'g';
	str5[7] = 'h';
	str5[8] = 'i';
	str5[9] = '\0';

	str6[0] = 'a';
	str6[1] = 'b';
	str6[2] = 'c';
	str6[3] = 'd';
	str6[4] = 'e';
	str6[5] = 'f';
	str6[6] = 'g';
	str6[7] = 'h';
	str6[8] = 'i';
	str6[9] = '\0';

	str = ft_strjoin_arg_free(6, str1, str2, str3, str4, str5, str6);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("ha pois", 1);
	free(str);
	return(0);
}*/
