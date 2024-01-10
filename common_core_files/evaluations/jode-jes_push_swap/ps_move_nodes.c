/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:45:17 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/03 18:56:43 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*return_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->bottom == cheapest->target->bottom)
	{
		if (cheapest->bottom)
			while (*a != cheapest->target && *b != cheapest)
				move(a, b, RRR);
		else
			while (*a != cheapest->target && *b != cheapest)
				move(a, b, RR);
	}
	finish_rotation(b, cheapest, RB, RRB);
	finish_rotation(a, cheapest->target, RA, RRA);
	move(a, b, PA);
}
