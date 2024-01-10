/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:01:14 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/13 19:22:44 by jorolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strcmp compares char by char the null terminated strings
// if a char does not match, it returns the difference between the chars.
// it returns > 0 if s1 > s2 ex. "hello" > "hel"
// it returns = 0 if s1 = s2 ex. "hello" = "hello"
// it returns < 0 if s1 < s2 ex. "hel" < "hello"
// while char of str 1 is equal to char of str2, go to next.
//if both strings are equal, the *s1 solves it to not go further '\0'
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
