/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:25:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 22:04:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rev_rotate(t_stack *stack)
{
	t_node	*node;

	node = popleft(stack);
	push(stack, node);
}

void	rra(t_data *data)
{
	write(1, "rra\n", 4);
	cmd_rotate(data->stack_a);
}

void	rrb(t_data *data)
{
	write(1, "rrb\n", 4);
	cmd_rotate(data->stack_b);
}

void	rrr(t_data *data)
{
	write(1, "rrr\n", 4);
	cmd_rotate(data->stack_a);
	cmd_rotate(data->stack_b);
}
