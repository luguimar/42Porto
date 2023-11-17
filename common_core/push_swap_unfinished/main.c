/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:56 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/17 02:38:50 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_stack(t_list *node)
{
	while (node)
	{
		ft_putnbr_fd(((t_node *)node->content)->value, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
	}
}

int	is_sorted(t_list *node)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	while (node)
	{
		temp_node = (t_node *)node->content;
		if (node->next
			&& !(temp_node->value < ((t_node *)node->next->content)->value))
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

t_list	*fill_stack(t_list **stack_a, char **args, int i)
{
	t_list	*temp_node;

	if (args)
	{
		*stack_a = ft_lstnew(ft_calloc(1, sizeof(t_node)));
		if (!*stack_a)
			return (NULL);
		temp_node = *stack_a;
	}
	while (args[++i])
	{
		((t_node *)(temp_node->content))->value = ft_atoi(args[i]);
		((t_node *)temp_node->content)->index = i;
		((t_node *)temp_node->content)->final_a_index = -1;
		if (args[i + 1])
			ft_lstadd_back(stack_a, ft_lstnew((t_node *)ft_calloc(1, sizeof(t_node))));
		if (!temp_node->next && args[i + 1])
		{
			ft_lstclear(stack_a, free);
			return (NULL);
		}
		if (args[i + 1])
			temp_node = temp_node->next;
	}
	temp_node->next = NULL;
	return (*stack_a);
}

void	wrong_args(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	arg_checker(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (args[i][j + 1] == '-')
			j++;
		while (args[i][++j] != '\0')
			if (!ft_isdigit(args[i][j]))
				return (0);
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (0);
	}
	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	**a;
	t_list	**b;

	a = (t_list **)ft_calloc(1, sizeof(t_list *));
	b = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!arg_checker(argc, argv))
		wrong_args();
	*a = fill_stack(a, argv + 1, -1);
	if (!a)
		wrong_args();
/*	if (!is_sorted(*a))
		sort(a, b);*/
	print_stack(*a);
	exec_operation(a, b, "sa");
	print_stack(*a);
	return (0);
}