/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:27:08 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/24 01:42:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	target_half(t_list *stack_a, int src_final_index)
{
	int		target_half;
	int		targt_index;

	targt_index = target_index(stack_a, src_final_index);
	if (targt_index < ft_lstsize(stack_a) / 2)
		target_half = 0;
	else
		target_half = 1;
	return (target_half);
}

int	target_inverse_index(t_list *stack_a, int src_final_index)
{
	int		target_inverse_index;
	int		targt_index;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	targt_index = target_index(stack_a, src_final_index);
	while (i < targt_index)
	{
		tmp = tmp->next;
		i++;
	}
	target_inverse_index = ((t_node *)tmp->content)->inverted_index;
	return (target_inverse_index);
}

int	target_index(t_list *stack_a, int src_final_index)
{
	t_list	*tmp;
	int		smallest_bigger_index;
	int		smallest_bigger_final_index;

	tmp = stack_a;
	smallest_bigger_index = -1;
	smallest_bigger_final_index = -1;
	while (tmp)
	{
		if ((((t_node *)tmp->content)->final_a_index > src_final_index) && \
				(((t_node *)tmp->content)->final_a_index \
				< smallest_bigger_final_index
				|| smallest_bigger_index == -1))
		{
			smallest_bigger_final_index = ((t_node *) \
					tmp->content)->final_a_index;
			smallest_bigger_index = ((t_node *)tmp->content)->index;
		}
		tmp = tmp->next;
	}
	return (smallest_bigger_index);
}

static t_node	*lstdup_node(t_node *content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content->value;
	node->index = content->index;
	node->final_a_index = content->final_a_index;
	return (node);
}

t_list	*lstdup(t_list *lst)
{
	t_list	*tmp;

	tmp = ft_lstnew(lstdup_node(lst->content));
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	wrong_args(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
