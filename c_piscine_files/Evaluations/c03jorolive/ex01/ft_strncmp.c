/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorolive <jorolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:23:46 by jorolive          #+#    #+#             */
/*   Updated: 2023/02/13 20:06:23 by jorolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//compares at most n bytes(chars) of s1 and s2, char by char.
//same cond as before but only compares max n chars.
//--n -> if n=4, the loop will run max n-1 to reach s1[3] and stop.
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 == *s2 && --n && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
