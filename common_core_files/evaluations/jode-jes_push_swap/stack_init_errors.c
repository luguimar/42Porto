/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:08:15 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/13 03:39:59 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_repetition(t_stack_node *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *argv_num)
{
	int	i;

	i = 0;
	if ((argv_num[i] == '+' || argv_num[i] == '-'))
		i++;
	if (!(argv_num[i] >= '0' && argv_num[i] <= '9'))
		return (1);
	while (argv_num[i])
	{
		if (!(argv_num[i] >= '0' && argv_num[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
main to test error_syntax
int	main(void)
{
	char	*str;

	str = "+1245";
	if (error_syntax(str) == 0)
		printf("done\n");
	if (error_syntax(str) == 1)
		printf("error\n");
}
*/