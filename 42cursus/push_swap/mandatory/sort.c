/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:53:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 17:22:59 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_element(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->top->value;
	mid = stack->top->next->value;
	bot = stack->top->next->next->value;
	if (top < mid && mid > bot && top < bot)
		ra sa rra
	else if (top < mid && mid > bot && top > bot)
		rra
	else if (top > mid && mid < bot && top < bot)
		sa
	else if (top > mid && mid < bot && top > bot)
		ra
	else if (top > mid && mid > bot && top > bot)
		sa rra
}
