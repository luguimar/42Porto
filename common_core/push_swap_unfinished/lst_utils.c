/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:27:08 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/25 00:36:48 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest(t_list *stack)
{
	t_list	*tmp;
	t_list	*biggest;
	t_node	*node;

	tmp = stack;
	biggest = tmp;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->value > ((t_node *)biggest->content)->value)
			biggest = tmp;
		tmp = tmp->next;
		if (tmp)
			node = (t_node *)tmp->content;
	}
	return (biggest);
}

t_list	*smallest(t_list *stack)
{
	t_list	*tmp;
	t_list	*smlst;
	t_node	*node;

	tmp = stack;
	smlst = tmp;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->value < ((t_node *)smlst->content)->value)
			smlst = tmp;
		tmp = tmp->next;
		if (tmp)
			node = (t_node *)tmp->content;
	}
	return (smlst);
}

int	sort_organized_price(t_list *stack)
{
	int		price;

	if (((t_node *)smallest(stack)->content)->half == 0)
		price = ((t_node *)smallest(stack)->content)->index;
	else
		price = ((t_node *)smallest(stack)->content)->inverted_index;
	return (price);
}

void	sort_organized(t_list **stack_a)
{
	int 	smlst_half;
	t_list	*smlst;
	t_list	*tmp;

	tmp = *stack_a;
	smlst = smallest(*stack_a);
	if (is_organized(tmp, ((t_node *)smlst->content)->final_a_index, ((t_node *)smlst->content)->index))
	{
		smlst_half = ((t_node *)smlst->content)->half;
		if (smlst_half == 0)
		{
			while (((t_node *)smlst->content)->index != 0)
				exec_operation(stack_a, NULL, "ra");
		}
		else
		{
			while (((t_node *)smlst->content)->index != 0)
				exec_operation(stack_a, NULL, "rra");
		}
	}
}

int	lowest_price_index(t_list *stack_b)
{
	t_list	*tmp;
	int		lowest_price;
	int		lowest_price_index;
	int		lowest_price_final_index;

	tmp = stack_b;
	lowest_price = -1;
	lowest_price_index = ((t_node *)tmp->content)->index;
	lowest_price_final_index = ((t_node *)tmp->content)->final_a_index;
	while (tmp)
	{
		if (((t_node *)tmp->content)->price < lowest_price || lowest_price == -1 || (((t_node *)tmp->content)->price == lowest_price && ((t_node *)tmp->content)->final_a_index < lowest_price_final_index))
		{
			lowest_price = ((t_node *)tmp->content)->price;
			lowest_price_index = ((t_node *)tmp->content)->index;
			lowest_price_final_index = ((t_node *)tmp->content)->final_a_index;
		}
		tmp = tmp->next;
	}
	return (lowest_price_index);
}

int	set_median(t_list *stack_a)
{
	t_list	*tmp;
	t_node	*node;

	tmp = stack_a;
	node = (t_node *)tmp->content;
	while (tmp)
	{
		if (node->final_a_index == ft_lstsize(stack_a) / 2)
			return (node->value);
		if (tmp->next)
			tmp = tmp->next;
		node = (t_node *)tmp->content;
	}
	return (node->value);
}

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
