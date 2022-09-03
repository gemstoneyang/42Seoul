/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_div_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:56:49 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/03 18:05:42 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_to_a_move(t_data *data, int size, int low_pivot, int high_pivot);
static void	b_to_a_next(t_data *data, int ra_count, int rb_count, int pa_count);

void	b_to_a(t_data *data, int size)
{
	int	low_pivot;
	int	high_pivot;

	if (size <= 0)
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
	low_pivot = three_div_low_pivot(data, data->stack_b, size);
	high_pivot = three_div_high_pivot(data, data->stack_b, size);
	b_to_a_move(data, size, low_pivot, high_pivot);
}

static void	b_to_a_move(t_data *data, int size, int low_pivot, int high_pivot)
{
	int		i;
	int		ra_count;
	int		rb_count;
	int		pa_count;
	t_node	*node;

	i = 0;
	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	while (i < size)
	{
		node = data->stack_b->top;
		if (node->value < low_pivot)
			rb_count += cmd("rb", data);
		else
		{
			pa_count += cmd("pa", data);
			if (node->value < high_pivot)
				ra_count += cmd("ra", data);
		}
		i++;
	}
	b_to_a_next(data, ra_count, rb_count, pa_count);
}

static void	b_to_a_next(t_data *data, int ra_count, int rb_count, int pa_count)
{
	int	i;

	a_to_b(data, pa_count - ra_count);
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
}
