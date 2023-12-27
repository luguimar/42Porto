/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:34:07 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/14 18:31:34 by jorolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strncat is similar to strcat, but:
// 1)it will use at most n bytes from src.
// 2)if src contains n or more bytes, does not need to be null terminated
// 3)if src contains n or more bytes, strncat writes n+1 bytes to dest
//   (n from src + '\0'). So dest size must be minimum (strlen(dest)+n+1).
// still has overflow issue if (src > dest)
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;

	i = 0;
	dest_len = 0;
	nb = 3;
	while (dest[i] != '\0')
		i++;
	dest_len = i;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
