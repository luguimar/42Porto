/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:37:13 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/24 00:18:59 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	node1 = (t_node *)(*stack_a)->content;
	node2 = (t_node *)(*stack_a)->next->content;
	node3 = (t_node *)(*stack_a)->next->next->content;
	if (node2->value > node3->value && node2->value > node1->value)
		exec_operation(stack_a, NULL, "rra");
	else if (node1->value > node2->value && node1->value > node3->value)
		exec_operation(stack_a, NULL, "ra");
	else
		exec_operation(stack_a, NULL, "sa");
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
	{
		exec_operation(stack_a, stack_b, "pb");
		set_index(stack_a, stack_b);
		set_inverse_index(stack_a, stack_b);
		set_half(stack_a, stack_b);
		set_price(stack_a, stack_b);
		print_stack(*stack_a);
		ft_putchar_fd('\n', 1);
		print_stack(*stack_b);
		ft_putchar_fd('\n', 1);
		print_prices(*stack_b);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) > 3)
	{
		exec_operation(stack_a, stack_b, "pb");
		set_index(stack_a, stack_b);
		set_inverse_index(stack_a, stack_b);
		set_half(stack_a, stack_b);
		set_price(stack_a, stack_b);
		print_stack(*stack_a);
		ft_putchar_fd('\n', 1);
		print_stack(*stack_b);
		ft_putchar_fd('\n', 1);
		print_prices(*stack_b);
	}
}

void	sort_many(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		stack_a_size;

	i = 0;
	stack_a_size = ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) > 3)
	{
		while (i < stack_a_size / 2)
		{
			exec_operation(stack_a, stack_b, "pb");
			i++;
		}
		set_index(stack_a, stack_b);
		set_inverse_index(stack_a, stack_b);
		set_half(stack_a, stack_b);
		set_price(stack_a, stack_b);
		ft_putchar_fd('\n', 1);
		print_stack(*stack_a);
		ft_putchar_fd('\n', 1);
		print_stack(*stack_b);
		ft_putchar_fd('\n', 1);
		print_prices(*stack_b);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
//	while (!is_sorted(*stack_a))
//	{
		if (ft_lstsize(*stack_a) == 2)
			exec_operation(stack_a, stack_b, "sa");
		else if (ft_lstsize(*stack_a) == 3)
			sort_three(stack_a);
		else if (ft_lstsize(*stack_a) == 4)
			sort_four(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		else
			sort_many(stack_a, stack_b);
//	}
}
