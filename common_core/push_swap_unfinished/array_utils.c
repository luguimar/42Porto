/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:17:30 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 16:29:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	*list_to_array(t_list *stack)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * ft_lstsize(stack));
	while (stack)
	{
		array[i] = ((t_node *)stack->content)->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

int	find_min(int *array, int size)
{
	int	i;
	int	min;

	i = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}
