/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:04:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/09 16:59:08 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *node)
{
	t_node	*top_node;

	if (stack->count == 0)
	{
		stack->top = node;
		stack->bot = node;
		stack->count += 1;
		return ;
	}
	top_node = stack->top;
	stack->top = node;
	node->next = top_node;
	top_node->prev = node;
	stack->count += 1;
}

#include <stdio.h>

void	pushleft(t_stack *stack, t_node *node)
{
	t_node	*bot_node;

	if (stack->top)
		printf("stack top : %p, %d\n", stack->top, stack->top->value);
	if (stack->count == 0)
	{
		stack->top = node;
		printf("stack top : %p, %d\n", stack->top, stack->top->value);
		stack->bot = node;
		stack->count += 1;
		return ;
	}
	bot_node = stack->bot;
	stack->bot = node;
	node->prev = bot_node;
	bot_node->next = node;
	stack->count += 1;
}

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (stack->count == 0)
		return (NULL);
	top_node = stack->top;
	stack->top = top_node->next;
	if (top_node->next)
	{
		top_node->next = NULL;
		stack->top->prev = NULL;
	}
	if (stack->count == 1)
		stack->bot = NULL;
	stack->count -= 1;
	return (top_node);
}

t_node	*popleft(t_stack *stack)
{
	t_node	*bot_node;

	if (stack->count == 0)
		return (NULL);
	bot_node = stack->bot;
	stack->bot = bot_node->prev;
	if (bot_node->prev)
	{
		bot_node->prev = NULL;
		stack->bot->next = NULL;
	}
	if (stack->count == 1)
		stack->top = NULL;
	stack->count -= 1;
	return (bot_node);
}
