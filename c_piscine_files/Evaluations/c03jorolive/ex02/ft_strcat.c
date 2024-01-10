/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:07:11 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/14 16:34:56 by jorolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//concatenation of two strings of source in dest, overwriting the null byte
//at end of dest, then adds terminating null byte.
//the dest must have enough space for the result.
//If dest is not large enough program behaviour is unpredictable.
//return a pointer to the resulting string dest.
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
