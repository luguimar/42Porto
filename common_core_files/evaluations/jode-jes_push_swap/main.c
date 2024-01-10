/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:06:04 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/13 14:46:38 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In the main
// if (argc == 2 && ft_strchr(argv[1], ' ')) #Filipe Azevedo code
// if (argc == 2)
//    argv = ft_split (argv[1], ' ');
// if (argv == NULL)
//	return (write(2, "Error\n", 6)); #Filipe Azevedo code
// In the stack init
// check syntax errors
// convert into int to compare similar things
// check overflow | underflow
// check duplicates/ repetitions
// if everything ok, append node,
// changing the address for which the pointer of the pointer is pointing.
// Its stops pointing to a list of empty arguments and starts pointing
// to the new created one.
// I will need atol. because argv is a char.
// In that sense I must convert it into an integer.
// The logic that: "I don´t need atol,
// because accordingly with the subject:
// In case of error,
// it must display "Error" followed by a ’\n’ on the standard error.
// Errors include for example: some arguments aren’t integers. So,
// we don´t need atol
// because if the input its not made ny integers,
// the code should give an error, and not
// transform a str into an integer. That´s not what the
// subject is asking us to do." becomes false.
// In the tiny_sort,
// highest_node = find_highest_node(*a)
// I´ve done the bellow code to substitue
// function above and to put only 5 functions on this folder (& not 6)

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
		push_b_save_3(a, b, len_a);
	tiny_sort_3(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->bottom)
		while (*a != smallest)
			move(a, a, RRA);
	else
		while (*a != smallest)
			move(a, a, RA);
}

void	tiny_sort_3(t_stack_node **a)
{
	t_stack_node	*highest_node;
	t_stack_node	*temp;
	int				highest;

	highest = INT_MIN;
	temp = *a;
	while (temp)
	{
		if (temp->value > highest)
		{
			highest = temp->value;
			highest_node = temp;
		}
		temp = temp->next;
	}
	if (*a == highest_node)
		move(a, a, RA);
	else if ((*a)->next == highest_node)
		move(a, a, RRA);
	if ((*a)->value > (*a)->next->value)
		move(a, a, SA);
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

void	stack_init(t_stack_node **a, char **argv)
{
	int		i;
	long	num;

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
		append_node(a, (int)num);
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
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			move(&a, &b, SA);
		else if (stack_len(a) == 3)
			tiny_sort_3(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}
