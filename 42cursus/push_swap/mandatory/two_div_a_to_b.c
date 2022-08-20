/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_div_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:47:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/20 21:21:51 by wonyang          ###   ########.fr       */
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
	low_pivot = three_div_low_pivot(data->stack_a, size);
	high_pivot = three_div_high_pivot(data->stack_a, size);
	if (low_pivot == -1 || high_pivot == -1)
		error_exit(data);
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
		{
			cmd("ra", data);
			ra_count++;
		}
		else
		{
			cmd("pb", data);
			pb_count++;
			if (node->value >= low_pivot)
			{
				cmd("rb", data);
				rb_count++;
			}
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
