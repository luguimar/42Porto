/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 05:28:25 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 05:29:13 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_aux(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		wrong_args();
	ft_printf("%s\n", line);
}

void	exec_operation(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "pb"))
		push(stack_a, stack_b);
	else
		operations_aux(stack_a, stack_b, line);
	ft_printf("%s\n", line);
}
