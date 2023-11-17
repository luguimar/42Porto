/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:37:13 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 22:00:00 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	(void )stack_a;
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	(void )stack_a;
	(void )stack_b;
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	(void )stack_a;
	(void )stack_b;
}

void 	sort_many(t_list **stack_a, t_list **stack_b)
{
	(void )stack_a;
	(void )stack_b;
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	while (!is_sorted(*stack_a))
	{
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
	}
}
