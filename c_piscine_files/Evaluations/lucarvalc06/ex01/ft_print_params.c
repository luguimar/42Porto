/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarval <lucarval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:12:39 by lucarval          #+#    #+#             */
/*   Updated: 2023/02/21 23:30:51 by lucarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ag, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ag)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			write (1, &av[i][j], 1);
			j++;
		}	
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

//a.out teste1 teste2 teste3
//av[0] av[1]  av[2]   av[3]
