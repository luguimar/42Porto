/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/22 05:17:38 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	set_half(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (((t_node *)tmp->content)->index < ft_lstsize(*stack_a) / 2)
			((t_node *)tmp->content)->half = 0;
		else
			((t_node *)tmp->content)->half = 1;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	while (tmp)
	{
		if (((t_node *)tmp->content)->index < ft_lstsize(*stack_b) / 2)
			((t_node *)tmp->content)->half = 0;
		else
			((t_node *)tmp->content)->half = 1;
		tmp = tmp->next;
	}
}

void	set_price(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		((t_node *)tmp->content)->price = -1;
		tmp = tmp->next;
	}
	tmp = *stack_b;
	while (tmp)
	{
		if (((t_node *)tmp->content)->half == 0 && target_half(*stack_a, ((t_node *)tmp->content)->final_a_index) == 0)
			((t_node *)tmp->content)->price = bigger(((t_node *)tmp->content)->index, set_target_index(*stack_a, ((t_node *)tmp->content)->final_a_index)) + 1;
		else if (((t_node *)tmp->content)->half == 1 && target_half(*stack_a, ((t_node *)tmp->content)->final_a_index) == 1)
			((t_node *)tmp->content)->price = ft_lstsize(*stack_b) 
		tmp = tmp->next;
	}
}

void	set_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		((t_node *)tmp->content)->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		((t_node *)tmp->content)->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_final_a_index(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_list	*smallest;

	i = 0;
	while (i < ft_lstsize(*stack_a))
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp == *stack_a)
			{
				while (((t_node *)tmp->content)->final_a_index != -1)
					tmp = tmp->next;
				smallest = tmp;
			}
			if (((t_node *)tmp->content)->value < ((t_node *)smallest->content) \
					->value && ((t_node *)tmp->content)->final_a_index == -1)
				smallest = tmp;
			tmp = tmp->next;
		}
		((t_node *)smallest->content)->final_a_index = i;
		i++;
	}
}

void	set_init_node_values(t_node *node, char **args, int i)
{
	node->value = ft_atoi(args[i]);
	node->index = i;
	node->final_a_index = -1;
	node->price = -1;
	node->half = -1;
}
