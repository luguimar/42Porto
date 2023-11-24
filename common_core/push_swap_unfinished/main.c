/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:56 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/24 00:16:34 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_half(t_list *stack_a)
{
	while (stack_a)
	{
		ft_putnbr_fd(((t_node *)stack_a->content)->half, 1);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->next;
	}
}

void	print_prices(t_list *stack_b)
{
	while (stack_b)
	{
		ft_putnbr_fd(((t_node *)stack_b->content)->price, 1);
		ft_putchar_fd('\n', 1);
		stack_b = stack_b->next;
	}
}

void	print_inverse_index(t_list *stack_a)
{
	while (stack_a)
	{
		ft_putnbr_fd(((t_node *)stack_a->content)->inverted_index, 1);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->next;
	}
}

void	print_index(t_list *stack_a)
{
	while (stack_a)
	{
		ft_putnbr_fd(((t_node *)stack_a->content)->index, 1);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->next;
	}
}

void	print_final_a_index(t_list *stack_a)
{
	while (stack_a)
	{
		ft_putnbr_fd(((t_node *)stack_a->content)->final_a_index, 1);
		ft_putchar_fd('\n', 1);
		stack_a = stack_a->next;
	}
}

void	print_stack(t_list *node)
{
	while (node)
	{
		ft_putnbr_fd(((t_node *)node->content)->value, 1);
		ft_putchar_fd('\n', 1);
		node = node->next;
	}
}

int	is_organized(t_list *node, int bigger_final_index,
		int bigger_final_index_index)
{
	t_list	*init_node;

	init_node = node;
	while (node)
	{
		if (((t_node *)node->content)->final_a_index > bigger_final_index)
		{
			bigger_final_index = ((t_node *)node->content)->final_a_index;
			bigger_final_index_index = ((t_node *)node->content)->index;
		}
		node = node->next;
	}
	while (init_node)
	{
		if ((((t_node *)init_node->content)->index <= bigger_final_index_index
				&& bigger_final_index_index - ((t_node *)init_node->content) \
				->index != bigger_final_index - ((t_node *)init_node->content) \
				->final_a_index) || (((t_node *)init_node->content)->index > \
					bigger_final_index_index && ((t_node *)init_node->content) \
					->index != ((t_node *)init_node->content)->final_a_index \
					+ bigger_final_index_index + 1))
			return (0);
		init_node = init_node->next;
	}
	return (1);
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

	if (args[0])
	{
		*stack_a = ft_lstnew(ft_calloc(1, sizeof(t_node)));
		if (!*stack_a)
			return (NULL);
		temp_node = *stack_a;
	}
	while (args[++i])
	{
		set_init_node_values((t_node *)temp_node->content, args, i);
		if (args[i + 1])
			ft_lstadd_back(stack_a, ft_lstnew((t_node *)ft_calloc(1,
						sizeof(t_node))));
		if (!temp_node->next && args[i + 1])
		{
			ft_lstclear(stack_a, free);
			return (NULL);
		}
		if (args[i + 1])
			temp_node = temp_node->next;
	}
	return (*stack_a);
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
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!arg_checker(argc, argv))
		wrong_args();
	a = fill_stack(&a, argv + 1, -1);
	if (!a && argc > 1)
		wrong_args();
	set_final_a_index(&a);
	ft_printf("final_a_index:\n");
	print_final_a_index(a);
	ft_putchar_fd('\n', 1);
	set_index(&a, &b);
	ft_printf("index:\n");
	print_index(a);
	ft_putchar_fd('\n', 1);
	set_inverse_index(&a, &b);
	ft_printf("inverse_index:\n");
	print_inverse_index(a);
	ft_putchar_fd('\n', 1);
	set_price(&a, &b);
	ft_printf("price:\n");
	print_prices(a);
	ft_putchar_fd('\n', 1);
	set_half(&a, &b);
	ft_printf("half:\n");
	print_half(a);
	ft_putchar_fd('\n', 1);
//	print_stack(a);
	if (!is_sorted(a))
		sort(&a, &b);
//	print_stack(a);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
