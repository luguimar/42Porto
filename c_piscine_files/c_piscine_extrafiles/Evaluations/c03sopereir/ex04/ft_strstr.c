/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopereir <sopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:02:33 by sopereir          #+#    #+#             */
/*   Updated: 2023/02/15 14:21:59 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	is_it_str(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	found;

	i = 0;
	while (str[i] != '\0' && found == 0)
	{
		if (str[i] == to_find[0])
			found = is_it_str(str + i, to_find);
		i++;
	}
	if (found)
		return (str + i - 1);
	else
		return (NULL);
}

int main()
{
	char dest[50]="mekie ta tudo bem mano";
	char *dest2=ft_strstr(dest,"ttudo bem");
	printf("%s\n%s\n",dest2,strstr(dest,"ttudo bem"));
	return 0;
}

