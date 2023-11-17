/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:05:47 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/17 02:03:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *novel)
{
	if (!*lst)
		*lst = novel;
	else
	{
		novel->next = NULL;
		if (*lst == NULL)
		{
			novel->prev = NULL;
			*lst = novel;
			return;
		}
		ft_lstlast(*lst)->next = novel;
		novel->prev = ft_lstlast(*lst);
	}
}
