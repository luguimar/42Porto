/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:04:00 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/17 02:04:06 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *novel)
{
	if (lst != NULL && novel != NULL)
	{
		novel->next = *lst;
		novel->prev = NULL;
		if (*lst != NULL)
			(*lst)->prev = novel;
		*lst = novel;
	}
}
