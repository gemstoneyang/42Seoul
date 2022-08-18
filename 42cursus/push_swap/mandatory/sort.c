/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:53:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/19 03:22:21 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_element(t_data *data)
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
		cmd("rra", data);
	else if (top > mid && mid < bot && top < bot)
		cmd("sa", data);
	else if (top > mid && mid < bot && top > bot)
		cmd("ra", data);
	else if (top > mid && mid > bot && top > bot)
		cmd("sa rra", data);
}
