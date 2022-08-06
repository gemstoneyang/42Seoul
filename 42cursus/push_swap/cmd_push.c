/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:12:31 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/06 16:15:18 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = pop(stack_b);
	push(stack_a, node);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pa\n", 3);
	if (stack_b->count == 0)
		return ;
	cmd_push(stack_a, stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pb\n", 3);
	if (stack_a->count == 0)
		return ;
	cmd_push(stack_b, stack_a);
}
