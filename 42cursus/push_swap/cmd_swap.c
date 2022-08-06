/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:06:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/06 15:25:39 by wonyang          ###   ########.fr       */
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

void	sa(t_stack *stack)
{
	write(1, "sa", 2);
	swap(stack);
}

void	sb(t_stack *stack)
{
	write(1, "sb", 2);
	swap(stack);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "ss", 2);
	swap(stack_a);
	swap(stack_b);
}
