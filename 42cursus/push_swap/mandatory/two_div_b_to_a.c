/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_div_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:49:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/20 00:40:47 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_data *data, int size)
{
	int		pivot;

	if (size == 0)
		return ;
	if (size == 1)
	{
		cmd("pa", data);
		return ;
	}
	if (size == 2)
	{
		sort_two_element_b(data);
		cmd("pa pa", data);
		return ;
	}
	if (size == 3)
	{
		sort_three_element_b(data);
		cmd("pa pa pa", data);
		return ;
	}
	pivot = two_div_pivot(data->stack_b);
	if (pivot == -1)
		error_exit(data);
	b_to_a_move(data, size, pivot);
}

void	b_to_a_move(t_data *data, int size, int pivot)
{
	int		i;
	int		rb_count;
	int		pa_count;
	t_node	*node;

	i = 0;
	rb_count = 0;
	pa_count = 0;
	while (i < size)
	{
		node = data->stack_b->top;
		if (node->value > pivot)
		{
			cmd("rb", data);
			rb_count++;
		}
		else
		{
			cmd("pa", data);
			pa_count++;
		}
		i++;
	}
	b_to_a_next(data, rb_count, pa_count);
}

void	b_to_a_next(t_data *data, int rb_count, int pa_count)
{
	int	i;

	i = 0;
	while (i < rb_count)
	{
		cmd("rrb", data);
		i++;
	}
	a_to_b(data, pa_count);
	b_to_a(data, rb_count);
}
