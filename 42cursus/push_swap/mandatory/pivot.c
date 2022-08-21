/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:10:13 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 19:50:50 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (size < 2)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*stack_to_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	node = stack->top;
	i = 0;
	while (i < size)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	return (arr);
}

int	three_div_low_pivot(t_data *data, t_stack *stack, int size)
{
	int	*arr;
	int	res;

	arr = stack_to_array(stack, size);
	if (!arr)
		error_exit(data);
	sort_array(arr, size);
	res = arr[size / 3];
	free(arr);
	return (res);
}

int	three_div_high_pivot(t_data *data, t_stack *stack, int size)
{
	int	*arr;
	int	res;

	arr = stack_to_array(stack, size);
	if (!arr)
		error_exit(data);
	sort_array(arr, size);
	res = arr[size * 2 / 3];
	free(arr);
	return (res);
}
