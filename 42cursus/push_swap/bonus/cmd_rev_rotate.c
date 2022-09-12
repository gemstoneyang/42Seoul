/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:25:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/12 15:48:37 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	cmd_rev_rotate(t_stack *stack)
{
	t_node	*node;

	node = popleft(stack);
	push(stack, node);
}

void	rra(t_data *data)
{
	if (data->stack_a->count < 2)
		return ;
	cmd_rev_rotate(data->stack_a);
}

void	rrb(t_data *data)
{	
	if (data->stack_b->count < 2)
		return ;
	cmd_rev_rotate(data->stack_b);
}

void	rrr(t_data *data)
{	
	if (data->stack_a->count < 2 || data->stack_b->count < 2)
		return ;
	cmd_rev_rotate(data->stack_a);
	cmd_rev_rotate(data->stack_b);
}
