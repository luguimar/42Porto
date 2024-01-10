/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catolive <catolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:22:24 by catolive          #+#    #+#             */
/*   Updated: 2023/02/14 11:35:50 by catolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	while (src[i] != '\0')
	{
		dest[c + i] = src[i];
		i++;
	}
	dest[c + i] = '\0';
	return (dest);
}
// int main(void)
// {
// 	char n[30] = "ola";
// 	char *n2 = "olas";
// 	printf("%s\n", ft_strcat(n, n2));
// }