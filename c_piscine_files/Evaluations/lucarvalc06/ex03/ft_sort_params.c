/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucarval <lucarval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:25:16 by lucarval          #+#    #+#             */
/*   Updated: 2023/02/21 23:29:20 by lucarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int ag, char **av)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < ag)
	{
		j = 1;
		while (j < ag)
		{
			if (ft_strcmp(av[i], av[j]) < 0)
			{
				temp = av[i];
				av[i] = av[j];
				av[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_putstr(av);
}
