/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:53:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 19:56:31 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_element_a(t_data *data)
{
	int		top;
	int		bot;
	t_stack	*stack;

	stack = data->stack_a;
	top = stack->top->value;
	bot = stack->top->next->value;
	if (top > bot)
		cmd("sa", data);
}

void	sort_two_element_b(t_data *data)
{
	int		top;
	int		bot;
	t_stack	*stack;

	stack = data->stack_b;
	top = stack->top->value;
	bot = stack->top->next->value;
	if (top < bot)
		cmd("sb", data);
}

void	sort_three_element_a(t_data *data)
{
	int		top;
	int		mid;
	int		bot;
	t_stack	*stack;

	stack = data->stack_a;
	top = stack->top->value;
	mid = stack->top->next->value;
	bot = stack->top->next->next->value;
	if (top < mid && mid > bot && top < bot)
		cmd("ra sa rra", data);
	else if (top < mid && mid > bot && top > bot)
		cmd("ra sa rra sa", data);
	else if (top > mid && mid < bot && top < bot)
		cmd("sa", data);
	else if (top > mid && mid < bot && top > bot)
		cmd("sa ra sa rra", data);
	else if (top > mid && mid > bot && top > bot)
		cmd("sa ra sa rra sa", data);
}

void	sort_three_element_b(t_data *data)
{
	int		top;
	int		mid;
	int		bot;
	t_stack	*stack;

	stack = data->stack_b;
	top = stack->top->value;
	mid = stack->top->next->value;
	bot = stack->top->next->next->value;
	if (top < mid && mid > bot && top < bot)
		cmd("sb rb sb rrb", data);
	else if (top < mid && mid > bot && top > bot)
		cmd("sb", data);
	else if (top > mid && mid < bot && top < bot)
		cmd("rb sb rrb sb", data);
	else if (top > mid && mid < bot && top > bot)
		cmd("rb sb rrb", data);
	else if (top < mid && mid < bot && top < bot)
		cmd("sb rb sb rrb sb", data);
}

void	sort_only_three_element(t_data *data)
{
	int		top;
	int		mid;
	int		bot;
	t_stack	*stack;

	stack = data->stack_a;
	top = stack->top->value;
	mid = stack->top->next->value;
	bot = stack->top->next->next->value;
	if (top < mid && mid > bot && top < bot)
		cmd("sa ra", data);
	else if (top < mid && mid > bot && top > bot)
		cmd("rra", data);
	else if (top > mid && mid < bot && top < bot)
		cmd("sa", data);
	else if (top > mid && mid < bot && top > bot)
		cmd("ra", data);
	else if (top > mid && mid > bot && top > bot)
		cmd("sa rra", data);
}
