/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/19 03:37:13 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	a_to_b_move(t_data *data, int size, int pivot)
{
	int		i;
	int		ra_count;
	int		pb_count;
	t_node	*node;

	i = 0;
	ra_count = 0;
	pb_count = 0
	while (i < size)
	{
		node = data->stack_a->top;
		if (node->value > pivot)
		{
			cmd("ra", data);
			ra_count++;
		}
		else
		{
			cmd("pb", data);
			pb_count++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		cmd("rra", data);
		i++;
	}
	a_to_b(data, ra_count);
	b_to_a(data, pb_count);
}

void	a_to_b(t_data *data, int size)
{
	int		pivot;

	if (size == 1)
		return ;
	pivot = two_div_pivot(data->stack_a);
	if (pivot == -1)
		error_exit(data);
	a_to_b_move(data, size, pivot);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	parse_nums(argc, argv, data);
	validation_data(argc, data);
	printf("%d\n", three_div_low_pivot(data->stack_a));
	printf("%d\n", three_div_high_pivot(data->stack_a));
	normal_exit(data);
	return (0);
}
