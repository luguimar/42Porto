/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:20:03 by jode-jes          #+#    #+#             */
/*   Updated: 2023/09/21 02:16:18 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **a)
{
	t_stack_node	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}

int	stack_len(t_stack_node *a)
{
	int	stack_len;

	stack_len = 0;
	while (a)
	{
		a = a->next;
		++stack_len;
	}
	return (stack_len);
}
