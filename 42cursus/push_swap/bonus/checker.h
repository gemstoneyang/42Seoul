/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:47:18 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/11 23:11:43 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"

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
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// cmd_rotate.c
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

// cmd_push.c
void	pa(t_data *data);
void	pb(t_data *data);

// cmd_swap.c
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

// cmd_stack.c
void	push(t_stack *stack, t_node *node);
void	pushleft(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
t_node	*popleft(t_stack *stack);

// error.c
void	error_exit(t_data *data);
void	normal_exit(t_data *data);

// init_data.c
t_data	*init_data(void);

// validation.c
void	validation_data(int argc, t_data *data);

// utils.c
t_bool	is_integer(char *str);
void	free_split(char **arr);
int		ft_strcmp(char *s1, char *s2);

// cmd_div.c
int		cmd(char *str, t_data *data);

// parse.c
void	parse_nums(int argc, char **argv, t_data *data);

// check_result.c
void	check_result(t_data *data);

#endif
