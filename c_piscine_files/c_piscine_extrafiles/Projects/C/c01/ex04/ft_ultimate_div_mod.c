/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:25:11 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/08 13:32:12 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;
	int	aux1;

	aux = *a;
	aux1 = *b;
	*a = aux / aux1;
	*b = aux % aux1;
}
