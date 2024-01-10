/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_b_save_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:06:23 by jode-jes          #+#    #+#             */
/*   Updated: 2023/09/21 02:30:47 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_final_index(t_stack_node *a, int size)
{
	t_stack_node	*temp;
	t_stack_node	*max_address;
	int				max_n;

	while (size--)
	{
		temp = a;
		max_n = INT_MIN;
		max_address = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->value > max_n && temp->final_index == 0)
			{
				max_n = temp->value;
				max_address = temp;
				temp = a;
			}
			else
				temp = temp->next;
		}
		if (max_address)
			max_address->final_index = size + 1;
	}
}

void	push_b_save_3(t_stack_node **a, t_stack_node **b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	get_final_index(*a, size);
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->final_index <= size / 2)
		{
			move(a, b, PB);
			pushed++;
		}
		else
			move(a, NULL, RA);
		i++;
	}
	while (size - pushed > 3)
	{
		move(a, b, PB);
		pushed++;
	}
}
