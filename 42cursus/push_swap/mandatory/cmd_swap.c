/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:06:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 21:55:40 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
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
	write(1, "sa\n", 3);
	swap(data->stack_a);
}

void	sb(t_data *data)
{
	write(1, "sb\n", 3);
	swap(data->stack_b);
}

void	ss(t_data *data)
{
	write(1, "ss\n", 3);
	swap(data->stack_a);
	swap(data->stack_b);
}
