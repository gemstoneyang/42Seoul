/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:05:14 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/16 22:53:54 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
	int				count;
}					t_stack;

typedef struct s_data
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_data;

void	cmd_rev_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	cmd_rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	cmd_push(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	cmd_swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	push(t_stack *stack, t_node *node);
void	pushleft(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
t_node	*popleft(t_stack *stack);

void	free_stack(t_stack *stack);
void	free_data(t_data *data);
void	error_exit(t_data *data);
void	normal_exit(t_data *data);

t_node	*init_node(int val);
t_stack	*init_stack(void);
t_data	*init_data(void);

void	parse_nums(int argc, char **argv, t_data *data);
void	add_num(char *str, t_data *data);
int		is_integer(char *str);
void	free_arr(char **arr);

#endif
