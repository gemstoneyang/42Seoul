/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:06:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/11 22:24:40 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = pop(stack);
	second = pop(stack);
	push(stack, first);
	push(stack, second);
}

void	sa(t_data *data)
{
	if (data->stack_a->count < 2)
		return ;
	add_cmd(data, "sa");
	swap(data->stack_a);
}

void	sb(t_data *data)
{
	if (data->stack_b->count < 2)
		return ;
	add_cmd(data, "sb");
	swap(data->stack_b);
}

void	ss(t_data *data)
{
	if (data->stack_a->count < 2 && data->stack_b->count < 2)
		return ;
	add_cmd(data, "ss");
	swap(data->stack_a);
	swap(data->stack_b);
}
