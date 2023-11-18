/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:27:08 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/18 03:40:41 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
