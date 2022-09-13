/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:35:31 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/13 20:33:13 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	duplicate_validation(t_data *data)
{
	t_node	*node;
	t_node	*cur_node;

	cur_node = data->stack_a->top;
	while (cur_node)
	{
		node = cur_node->next;
		while (node)
		{
			if (cur_node->value == node->value)
				error_exit(data);
			node = node->next;
		}
		cur_node = cur_node->next;
	}
}

static void	sorted_validation(t_data *data)
{
	t_node	*node;

	node = data->stack_a->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return ;
		node = node->next;
	}
	normal_exit(data);
}

void	validation_data(int argc, t_data *data)
{
	if (argc < 2 || data->stack_a->count == 0)
		normal_exit(data);
	duplicate_validation(data);
	sorted_validation(data);
}
