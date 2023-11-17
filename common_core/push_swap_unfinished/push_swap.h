/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:56:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/16 23:40:29 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int	value;
	int	index;
	int	final_a_index;
}		t_node;

int		is_sorted(t_list *node);
void	wrong_args(void);
void	swap(t_list **stack);
void	push(t_list **stack_orig, t_list **stack_dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	operations_aux(t_list **stack_a, t_list **stack_b, char *line);
void	exec_operation(t_list **stack_a, t_list **stack_b, char *line);
void	sort(t_list **stack_a, t_list **stack_b);
void	set_index(t_list **stack_a, t_list **stack_b);
void	set_final_a_index(t_list **stack_a);
int		*list_to_array(t_list *stack);
int		find_min(int *array, int size);
t_list	*lstdup(t_list *lst);

#endif
