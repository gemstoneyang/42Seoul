/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:25:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 19:44:09 by wonyang          ###   ########.fr       */
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
	if (data->stack_a->count < 2)
		return ;
	add_cmd(data, "rra");
	cmd_rev_rotate(data->stack_a);
}

void	rrb(t_data *data)
{	
	if (data->stack_b->count < 2)
		return ;
	add_cmd(data, "rrb");
	cmd_rev_rotate(data->stack_b);
}

void	rrr(t_data *data)
{	
	if (data->stack_a->count < 2 && data->stack_b->count < 2)
		return ;
	add_cmd(data, "rrr");
	cmd_rev_rotate(data->stack_a);
	cmd_rev_rotate(data->stack_b);
}
