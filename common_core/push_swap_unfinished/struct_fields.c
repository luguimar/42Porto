/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 15:50:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				smallest = tmp;
			else if (((t_node *)tmp->content)->value < \
					((t_node *)smallest->content)->value)
				smallest = tmp;
			tmp = tmp->next;
		}
		((t_node *)smallest->content)->final_a_index = i;
	}
}
