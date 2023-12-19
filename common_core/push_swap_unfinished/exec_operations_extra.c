/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:11:55 by luguimar          #+#    #+#             */
/*   Updated: 2023/12/19 18:12:29 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half == ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 1)
				exec_operation(stack_a, stack_b, "rrr");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half == ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 0 && node->index != 0
				&& ((t_node *)smallest(*stack_a)->content)->index != 0)
				exec_operation(stack_a, stack_b, "rr");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half != ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 0 && node->index == 0)
				exec_operation(stack_a, stack_b, "rra");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half != ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 1
				&& ((t_node *)smallest(*stack_a)->content)->index == 0)
				exec_operation(stack_a, stack_b, "rrb");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half != ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 1
				&& ((t_node *)smallest(*stack_a)->content)->index != 0)
			{
				exec_operation(stack_a, stack_b, "ra");
				exec_operation(stack_a, stack_b, "rrb");
			}
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half != ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 1
				&& ((t_node *)smallest(*stack_a)->content)->index == 0)
				exec_operation(stack_a, stack_b, "rb");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half == ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 0 && node->index == 0
				&& ((t_node *)smallest(*stack_a)->content)->index != 0)
				exec_operation(stack_a, stack_b, "ra");
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half != ((t_node *)smallest(*stack_a)->content)->half
				&& node->half == 0 && node->index != 0)
			{
				exec_operation(stack_a, stack_b, "rb");
				exec_operation(stack_a, stack_b, "rra");
			}
			else if (node->value > ((t_node *)biggest(*stack_a)->content)->value
				&& node->half == ((t_node *)smallest(*stack_a)->content)->half
				&& node->index == 0
				&& ((t_node *)smallest(*stack_a)->content)->index == 0)
				exec_operation(stack_a, stack_b, "pa");
			else if (node->index == 0 && target_index(*stack_a,
					node->final_a_index) == 0)
				exec_operation(stack_a, stack_b, "pa");
			else if (target_half(*stack_a, node->final_a_index) == 0
				&& node->index == 0 && target_index(*stack_a,
					node->final_a_index) != 0)
				exec_operation(stack_a, stack_b, "ra");
			else if (node->half == 0 && node->index != 0
				&& target_index(*stack_a, node->final_a_index) == 0)
				exec_operation(stack_a, stack_b, "rb");
			else if (node->half == 0 && target_half(*stack_a,
					node->final_a_index) == 0 && node->index != 0
				&& target_index(*stack_a, node->final_a_index) != 0)
				exec_operation(stack_a, stack_b, "rr");
			else if (node->half == 0 && target_half(*stack_a,
					node->final_a_index) != 0 && node->index == 0)
				exec_operation(stack_a, stack_b, "rra");
			else if (node->half == 0 && target_half(*stack_a,
					node->final_a_index) != 0 && node->index != 0)
			{
				exec_operation(stack_a, stack_b, "rb");
				exec_operation(stack_a, stack_b, "rra");
			}
			else if (node->half != 0 && target_half(*stack_a,
					node->final_a_index) == 0 && target_index(*stack_a,
					node->final_a_index) == 0)
				exec_operation(stack_a, stack_b, "rrb");
			else if (node->half != 0 && target_half(*stack_a,
					node->final_a_index) == 0 && target_index(*stack_a,
					node->final_a_index) != 0)
			{
				exec_operation(stack_a, stack_b, "ra");
				exec_operation(stack_a, stack_b, "rrb");
			}
			else if (node->half != 0 && target_index(*stack_a,
					node->final_a_index) == 0)
				exec_operation(stack_a, stack_b, "rrb");
			else if (node->half != 0 && target_half(*stack_a,
					node->final_a_index) == 0 && target_index(*stack_a,
					node->final_a_index) != 0)
			{
				exec_operation(stack_a, stack_b, "ra");
				exec_operation(stack_a, stack_b, "rrb");
			}
			else if (node->half != 0 && target_half(*stack_a,
					node->final_a_index) != 0)
				exec_operation(stack_a, stack_b, "rrr");
			break ;
		}
		tmp = tmp->next;
	}
}
