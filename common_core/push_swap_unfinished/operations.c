/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:59:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/17 02:10:03 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup((*stack)->next);
		ft_lstdelone(stack, (*stack)->next, free);
		ft_lstadd_front(stack, tmp);
	}
}

void	push(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_orig) > 0)
	{
		tmp = lstdup(*stack_orig);
		ft_lstdelone(stack_orig, (*stack_orig), free);
		ft_lstadd_front(stack_dest, tmp);
	}
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup(*stack);
		*stack = (*stack)->next;
		ft_lstdelone(stack, (*stack)->prev, free);
		ft_lstadd_back(stack, tmp);
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = lstdup(ft_lstlast(*stack));
		ft_lstdelone(stack, ft_lstlast(*stack), free);
		ft_lstadd_front(stack, tmp);
	}
}
