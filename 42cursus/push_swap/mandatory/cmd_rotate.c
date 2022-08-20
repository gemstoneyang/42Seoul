/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:19:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 02:23:42 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rotate(t_stack *stack)
{
	t_node	*node;

	node = pop(stack);
	pushleft(stack, node);
}

void	ra(t_data *data)
{
	add_cmd(data, "ra");
	cmd_rotate(data->stack_a);
}

void	rb(t_data *data)
{
	add_cmd(data, "rb");
	cmd_rotate(data->stack_b);
}

void	rr(t_data *data)
{
	add_cmd(data, "rr");
	cmd_rotate(data->stack_a);
	cmd_rotate(data->stack_b);
}
