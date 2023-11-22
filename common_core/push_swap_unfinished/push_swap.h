/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:56:06 by luguimar          #+#    #+#             */
/*   Updated: 2023/11/22 05:12:22 by luguimar         ###   ########.fr       */
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
	int	price;
	int	half;
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
t_list	*lstdup(t_list *lst);
void	set_init_node_values(t_node *node, char **args, int i);
void	set_price(t_list **stack_a, t_list **stack_b);
int		set_target_index(t_list *stack_a, int src_final_index);
int		bigger(int a, int b);
int		smaller(int a, int b);
void	set_half(t_list **stack_a, t_list **stack_b);
int		target_half(t_list *stack_a, int src_final_index);

#endif
