/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:45:41 by jode-jes          #+#    #+#             */
/*   Updated: 2023/09/22 12:00:56 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// after *a = new_node:
// new_node->prev = NULL //codigo do Filipe
// after last_node->next = new_node;:
// new_node->previous = last_node // Filipe code

void	append_node(t_stack_node **a, int num)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (a == NULL)
		return ;
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node->value = num;
	new_node->final_index = 0;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	last_node = *a;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
}

long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		isneg;

	num = 0;
	i = 0;
	isneg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}
