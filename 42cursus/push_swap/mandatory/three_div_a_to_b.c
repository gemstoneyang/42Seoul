/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_div_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:56:43 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 20:16:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_data *data, int size)
{
	int	low_pivot;
	int	high_pivot;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		sort_two_element_a(data);
		return ;
	}
	if (size == 3)
	{
		sort_three_element_a(data);
		return ;
	}
	low_pivot = three_div_low_pivot(data, data->stack_a, size);
	high_pivot = three_div_high_pivot(data, data->stack_a, size);
	a_to_b_move(data, size, low_pivot, high_pivot);
}

void	a_to_b_move(t_data *data, int size, int low_pivot, int high_pivot)
{
	int		i;
	int		ra_count;
	int		rb_count;
	int		pb_count;
	t_node	*node;

	i = 0;
	ra_count = 0;
	rb_count = 0;
	pb_count = 0;
	while (i < size)
	{
		node = data->stack_a->top;
		if (node->value >= high_pivot)
			ra_count += cmd("ra", data);
		else
		{
			pb_count += cmd("pb", data);
			if (node->value >= low_pivot)
				rb_count += cmd("rb", data);
		}
		i++;
	}
	a_to_b_next(data, ra_count, rb_count, pb_count);
}

void	a_to_b_next(t_data *data, int ra_count, int rb_count, int pb_count)
{
	int	i;

	i = 0;
	while (i < ra_count && i < rb_count)
	{
		cmd("rrr", data);
		i++;
	}
	while (i < ra_count)
	{
		cmd("rra", data);
		i++;
	}
	while (i < rb_count)
	{
		cmd("rrb", data);
		i++;
	}
	a_to_b(data, ra_count);
	b_to_a(data, rb_count);
	b_to_a(data, pb_count - rb_count);
}
