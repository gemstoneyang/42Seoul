/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:05:14 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/19 15:15:55 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

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

// cmd_rev_rotate.c
void	cmd_rev_rotate(t_stack *stack);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// cmd_rotate.c
void	cmd_rotate(t_stack *stack);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

// cmd_push.c
void	pa(t_data *data);
void	pb(t_data *data);

// cmd_swap.c
void	cmd_swap(t_stack *stack);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

// cmd_stack.c
void	push(t_stack *stack, t_node *node);
void	pushleft(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
t_node	*popleft(t_stack *stack);

// error.c
void	free_stack(t_stack *stack);
void	free_data(t_data *data);
void	error_exit(t_data *data);
void	normal_exit(t_data *data);

// init_data.c
t_bool	is_integer(char *str);
t_node	*init_node(char *str);
t_stack	*init_stack(void);
t_data	*init_data(void);

// validation.c
void	duplicate_validation(t_data *data);
void	sorted_validation(t_data *data);
void	validation_data(int argc, t_data *data);

// utils.c
void	free_split(char **arr);
int		ft_strcmp(char *s1, char *s2);

// cmd_div.c
void	cmd_div(char *cmd, t_data *data);
void	cmd(char *str, t_data *data);

// pivot.c
void	sort_array(int *arr, int size);
int		*stack_to_array(t_stack *stack);
int		three_div_low_pivot(t_stack *stack);
int		three_div_high_pivot(t_stack *stack);
int		two_div_pivot(t_stack *stack);

// sort.c
void	sort_three_element(t_data *data);

// parse.c
void	parse_nums(int argc, char **argv, t_data *data);
void	add_num(char *str, t_data *data);
int		is_integer(char *str);

// two_div_a_to_b.c
void	a_to_b(t_data *data, int size);
void	a_to_b_move(t_data *data, int size, int pivot);
void	a_to_b_next(t_data *data, int ra_count, int pb_count);

// two_div_b_to_a.c
void	b_to_a(t_data *data, int size);
void	b_to_a_move(t_data *data, int size, int pivot);
void	b_to_a_next(t_data *data, int rb_count, int pa_count);

#endif
