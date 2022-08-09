/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:19:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/09 16:36:30 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rotate(t_stack *stack)
{
	t_node	*node;

	node = pop(stack);
	pushleft(stack, node);
}

void	ra(t_stack *stack_a)
{
	write(1, "ra\n", 3);
	cmd_rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	write(1, "rb\n", 3);
	cmd_rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rr\n", 3);
	cmd_rotate(stack_a);
	cmd_rotate(stack_b);
}
