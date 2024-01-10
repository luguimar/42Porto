/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:55:18 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 21:56:09 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && n >= ft_strlen(little))
	{
		if (ft_strncmp(&big[i], little, ft_strlen(little)) == 0)
			return ((char *)&big[i]);
		i++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	const char *bigstr = "Foo Bar Baz";
        const char *littlestr = "Bar";
        char *ptr;

        ptr = ft_strnstr(bigstr, littlestr, 10);
        printf("ft_strnstr: %s\n", ptr);

}*/