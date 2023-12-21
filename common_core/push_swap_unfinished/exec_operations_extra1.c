/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_extra1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:39 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/21 11:46:17 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_rb(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if ((node->value > ((t_node *)biggest(*stack_a)->content)->value && \
				node->half != ((t_node *)smallest(*stack_a) \
					->content)->half && node->half == 1 && \
				((t_node *)smallest(*stack_a)->content)->index == 0) \
			|| (node->half == 0 && node->index != 0 && target_index \
				(*stack_a, node->final_a_index) == 0))
		exec_operation(stack_a, stack_b, "rb");
}

void	is_ra(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if ((node->value > ((t_node *)biggest(*stack_a)->content)->value && \
				node->half == ((t_node *)smallest(*stack_a)-> \
					content)->half && node->half == 0 && node \
				->index == 0 && ((t_node *)smallest(*stack_a)-> \
					content)->index != 0) || (target_half \
					(*stack_a, node->final_a_index) == 0 && \
					node->index == 0 && target_index(*stack_a, \
						node->final_a_index) != 0))
		exec_operation(stack_a, stack_b, "ra");
}

void	is_rb_rra(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if ((node->value > ((t_node *)biggest(*stack_a)->content)->value && \
				node->half != ((t_node *)smallest(*stack_a)->content) \
				->half && node->half == 0 && node->index != 0) || \
			(node->half == 0 && target_half(*stack_a, node->final_a_index) \
			!= 0 && node->index != 0))
	{
		exec_operation(stack_a, stack_b, "rb");
		exec_operation(stack_a, stack_b, "rra");
	}
}

void	is_pa(t_list **stack_a, t_list **stack_b, t_node *node)
{
	if ((node->value > ((t_node *)biggest(*stack_a)->content)->value && \
				node->half == ((t_node *)smallest(*stack_a)->content) \
				->half && node->index == 0 && ((t_node *)smallest \
					(*stack_a)->content)->index == 0) || \
			(node->index == 0 && target_index(*stack_a, node-> \
							final_a_index) == 0))
		exec_operation(stack_a, stack_b, "pa");
}