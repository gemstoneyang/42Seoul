/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:04:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/05 02:22:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	t_node	*top_node;

	stack->count += 1;
	if (stack->top == NULL)
	{
		stack->top = node;
		stack->bot = node;
		return ;
	}
	top_node = stack->top;
	stack->top = node;
	node->next = top_node;
	top_node->prev = node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (stack->count == 0)
		return (NULL);
	stack->count -= 1;
	top_node = stack->top;
	stack->top = top_node->next;
	if (stack->count == 0)
		stack->bot = NULL;

}
