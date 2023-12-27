/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:02:05 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/04 14:55:14 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	imprime_vec(char **v, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i <= x)
	{
		while(j <= y)
		{
			ft_putchar(v[i][j]);
			j++;
		}
		i++;
	}
}

void	assist1(int i, int j, int x, int y, char **vec)
{
	while(i <= x)
	{
		while(j <= y)
		{
			if((i == 0 || i == x) && j == 0)
			{
				vec[i][j] = 'A';
			}
			else if((i == 0 || i == x) && j == y)
			{
				vec[i][j] = 'C';
			}
			else if(i > 0 && i < x && j != 0 && j != y)
			{
				vec[i][j] = 'B';
			}
			j++;
		}
		i++;
	}
	imprime_vec(vec, x, y);
}

void	rush02(int x, int y)
{
	int	i;
	int	j;
	char	**vec;

	i = 0;
	j = 0;
	assist1(i, j, x, y, vec);
}
