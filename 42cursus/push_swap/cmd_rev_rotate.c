/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:25:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/06 16:15:18 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rev_rotate(t_stack *stack)
{
	t_node	*node;

	node = popleft(stack);
	push(stack, node);
}

void	rra(t_stack *stack_a)
{
	write(1, "rra\n", 4);
	cmd_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	write(1, "rrb\n", 4);
	cmd_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	cmd_rotate(stack_a);
	cmd_rotate(stack_b);
}
