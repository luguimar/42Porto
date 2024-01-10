/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:34:26 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/13 14:46:55 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	move_checker(t_stack_node **a, t_stack_node **b, char *cmd)
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
	else
	{
		free(cmd);
		free_stack(a);
		free_stack(b);
		error_exit();
	}
}

bool	stack_is_sorted(t_stack_node *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

static void	checker(t_stack_node **a, t_stack_node **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		move_checker(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
}

void	stack_init(t_stack_node **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a);
		if (error_repetition(*a, num))
			error_free(a);
		append_node(a, num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	stack_init(&a, argv + 1);
	checker(&a, &b);
	if (stack_is_sorted(a) && !b)
		ft_putendl_fd("Ok", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
