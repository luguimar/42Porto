/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:28:25 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 18:56:49 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exec_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		lwest_price_index;
	t_list	*tmp;
	t_node	*node;

	tmp = *stack_b;
	lwest_price_index = lowest_price_index(*stack_b);
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (node->index == lwest_price_index)
		{
			is_rrr(stack_a, stack_b, node);
			is_rr(stack_a, stack_b, node);
			is_rra(stack_a, stack_b, node);
			is_rrb(stack_a, stack_b, node);
			is_ra_rrb(stack_a, stack_b, node);
			is_rb(stack_a, stack_b, node);
			is_ra(stack_a, stack_b, node);
			is_rb_rra(stack_a, stack_b, node);
			is_pa(stack_a, stack_b, node);
			break ;
		}
		tmp = tmp->next;
	}
}

void	operations_aux(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		wrong_args(*stack_a, *stack_b, line);
}

void	exec_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_a, stack_b);
	else
		operations_aux(stack_a, stack_b, line);
}
