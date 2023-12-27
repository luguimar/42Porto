/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:36:10 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/15 15:37:02 by jorolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//safer concatenation of strings than strncat.
//it takes full size of buffer (not just len)
// (size is the nr of bytes allocated to it)
// (len in the nr of bytes actually in use)
//and add \0 in the end, as long as there is one byte free in dest.
//only operates if both strings end in \0.
//appends at most (size - strlen(dest) -1) "src\0" in the end of dest
//
//RETURN VALUES
//returns the total len of the string they tried to create
//that is, the initial len of dst + initial len of src.
//CATCH:
//if it iterates without finding a null, the len of string is size
// and dest string will not be null terminated
//(as there was no space for the null)
//if the return value >= destsize, the output string has been truncated.

int	sum_size(char *src, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(src + i))
		i++;
	while (*(dest + j))
		j++;
	return (i + j);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	j;
	int	cat_space;

	j = 0;
	while (*(dest + j))
		j++;
	cat_space = (size - j) - 1;
	while (*src && cat_space--)
		*(dest + j++) = *src++;
	*(dest + j) = '\0';
	return (sum_size(dest, src));
}
