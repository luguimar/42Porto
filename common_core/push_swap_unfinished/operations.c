/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:59:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 05:28:12 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	if (ft_lstsize(*stack) > 1)
	{
		(*stack)->next = (*stack)->next->next;
		(*stack)->next->prev->next = (*stack);
		(*stack)->prev = (*stack)->next->prev;
		(*stack)->next->prev = (*stack);
		(*stack) = (*stack)->prev;
		(*stack)->prev = NULL;
	}
}

void	push(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_orig) > 0)
	{
		tmp = *stack_orig;
		*stack_orig = (*stack_orig)->next;
		(*stack_orig)->prev = NULL;
		if (ft_lstsize(*stack_dest) > 0)
			ft_lstadd_front(stack_dest, tmp);
		else
		{
			*stack_dest = tmp;
			(*stack_dest)->next = NULL;
			(*stack_dest)->prev = NULL;
		}
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = ft_lstlast(*stack);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		ft_lstadd_front(stack, tmp);
	}
}
