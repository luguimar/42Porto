/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:24:01 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/10 12:36:25 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack_node **stack, t_stack_node *cheap, char *rx,
		char *rrx)
{
	while (*stack != cheap)
	{
		if (cheap->bottom)
			move(stack, stack, rrx);
		else
			move(stack, stack, rx);
	}
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
