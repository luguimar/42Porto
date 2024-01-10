/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:27:26 by pemontei          #+#    #+#             */
/*   Updated: 2023/05/10 22:37:22 by pemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strdup() function allocates sufficient memory for a copy of the
 * string s, does the copy, and returns a pointer to it.  The pointer may
 * subsequently be used as an argument to the function free(3).
 * If insufficient memory is available, NULL is returned.
 */
char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*int main()
{
    char orig_str[12] = "Itsy bitsy!";
    char *dup_str;
    int o_len,d_len;

    dup_str = ft_strdup(orig_str);
    o_len = strlen(orig_str);
    d_len = strlen(dup_str);

    printf("Original String: '%s' (%d)\n",
            orig_str,o_len);
    printf("Duplicate string: '%s' (%d)\n",
            dup_str,d_len);

    return(0);
}*/