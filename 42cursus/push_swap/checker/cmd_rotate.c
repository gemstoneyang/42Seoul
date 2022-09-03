/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:19:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/03 17:57:42 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cmd_rotate(t_stack *stack)
{
	t_node	*node;

	node = pop(stack);
	pushleft(stack, node);
}

void	ra(t_data *data)
{
	if (data->stack_a->count < 2)
		return ;
	add_cmd(data, "ra");
	cmd_rotate(data->stack_a);
}

void	rb(t_data *data)
{
	if (data->stack_b->count < 2)
		return ;
	add_cmd(data, "rb");
	cmd_rotate(data->stack_b);
}

void	rr(t_data *data)
{
	if (data->stack_a->count < 2 && data->stack_b->count < 2)
		return ;
	add_cmd(data, "rr");
	cmd_rotate(data->stack_a);
	cmd_rotate(data->stack_b);
}
