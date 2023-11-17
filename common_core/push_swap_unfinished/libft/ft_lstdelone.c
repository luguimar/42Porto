/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:18:00 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/17 01:44:43 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **head, t_list *lst, void (*del)(void *))
{
	if (head && lst && del)
	{
		del(lst->content);
		if (*head == lst)
			*head = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
		if (lst->prev)
			lst->prev->next = lst->next;
		free(lst);
	}
}
