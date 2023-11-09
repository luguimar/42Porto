/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:56 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/09 19:22:17 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_list **node, char **args)
{
	int	i;
	t_list	*temp_node;

	i = 0;
	if (args + 1)
		*node = ft_lstnew((t_node*) ft_calloc(1, sizeof(t_node)));
	while (++args)
	{
		(*node)->content->value = ft_atoi(*args);
		(*node)->content->index = i;
		(*node)->content->final_a_index = -1;
	}
}

void	wrong_args(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	arg_checker(int argc,char **args)
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
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!arg_checker(argc, argv))
		wrong_args();
	fill_stack(&stack_a, argv);
	return (0);
}
