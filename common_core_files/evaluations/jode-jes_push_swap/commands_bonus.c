/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:14:07 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/12 20:57:55 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **a, t_stack_node **b, char *cmd)
{
	t_stack_node	*tmp;

	if (!ft_strncmp(cmd, SA, ft_strlen(SA)) || !ft_strncmp(cmd, SS,
			ft_strlen(SS)))
	{
		if (!*a || !(*a)->next)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (!ft_strncmp(cmd, SB, ft_strlen(SB)) || !ft_strncmp(cmd, SS,
			ft_strlen(SS)))
		swap(b, a, SA);
}

void	push_func(t_stack_node **a, t_stack_node **b, char *cmd)
{
	t_stack_node	*tmp;

	if (!ft_strncmp(cmd, PA, ft_strlen(PA)))
	{
		if (!*b)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (!ft_strncmp(cmd, PB, ft_strlen(PB)))
		push_func(b, a, PA);
}

void	rotate(t_stack_node **a, t_stack_node **b, char *cmd)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!ft_strncmp(cmd, RA, ft_strlen(RA)) || !ft_strncmp(cmd, RR,
			ft_strlen(RR)))
	{
		if (!*a || !(*a)->next)
			return ;
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	if (!ft_strncmp(cmd, RB, ft_strlen(RB)) || !ft_strncmp(cmd, RR,
			ft_strlen(RR)))
		rotate(b, a, RA);
}

void	reverse_rotate(t_stack_node **a, t_stack_node **b, char *cmd)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!ft_strncmp(cmd, RRA, ft_strlen(RRA)) || !ft_strncmp(cmd, RRR,
			ft_strlen(RRR)))
	{
		if (!*a || !(*a)->next)
			return ;
		temp = *a;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (!ft_strncmp(cmd, RRB, ft_strlen(RRB)) || !ft_strncmp(cmd, RRR,
			ft_strlen(RRR)))
		reverse_rotate(b, a, RRA);
}

void	move(t_stack_node **a, t_stack_node **b, char *cmd)
{
	if (!ft_strncmp(cmd, SA, ft_strlen(SA)) || !ft_strncmp(cmd, SB,
			ft_strlen(SB)) || !ft_strncmp(cmd, SS, ft_strlen(SS)))
		swap(a, b, cmd);
	else if (!ft_strncmp(cmd, PA, ft_strlen(PA)) || !ft_strncmp(cmd, PB,
			ft_strlen(PB)))
		push_func(a, b, cmd);
	else if (!ft_strncmp(cmd, RA, ft_strlen(RA)) || !ft_strncmp(cmd, RB,
			ft_strlen(RB)) || !ft_strncmp(cmd, RR, ft_strlen(RR)))
		rotate(a, b, cmd);
	else if (!ft_strncmp(cmd, RRA, ft_strlen(RRA)) || !ft_strncmp(cmd, RRB,
			ft_strlen(RRB)) || !ft_strncmp(cmd, RRR, ft_strlen(RRR)))
		reverse_rotate(a, b, cmd);
	ft_putstr_fd(cmd, 1);
}
