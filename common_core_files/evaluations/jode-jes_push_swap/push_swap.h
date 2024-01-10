/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:07:32 by jode-jes          #+#    #+#             */
/*   Updated: 2023/10/13 02:52:51 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct t_stack_node
{
	int					value;
	int					position;
	int					final_index;
	int					price;
	bool				bottom;
	struct t_stack_node	*target;
	struct t_stack_node	*next;
}						t_stack_node;

void					free_stack(t_stack_node **a);
// void	free_array(char **argv);
long					ft_atol(const char *str);
// void	error_exit(void);
void					append_node(t_stack_node **head, int value);
int						stack_len(t_stack_node *stack);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					tiny_sort_3(t_stack_node **stack);
void					sort_five(t_stack_node **a, t_stack_node **b);
bool					stack_is_sorted(t_stack_node *stack);
void					set_current_position(t_stack_node *stack);
t_stack_node			*find_smallest(t_stack_node *stack);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					swap(t_stack_node **a, t_stack_node **b, char *cmd);
void					push_func(t_stack_node **src, t_stack_node **dst,
							char *cmd);
void					rotate(t_stack_node **a, t_stack_node **b, char *cmd);
void					reverse_rotate(t_stack_node **a, t_stack_node **b,
							char *cmd);
void					move(t_stack_node **first, t_stack_node **second,
							char *cmd);
void					move_nodes(t_stack_node **a, t_stack_node **b);
void					finish_rotation(t_stack_node **stack,
							t_stack_node *cheap, char *rx, char *rrx);
void					error_free(t_stack_node **a);
int						error_repetition(t_stack_node *a, int nbr);
int						error_syntax(char *nbr);
void					push_b_save_3(t_stack_node **a, t_stack_node **b,
							int size);
void					error_exit(void);

#endif