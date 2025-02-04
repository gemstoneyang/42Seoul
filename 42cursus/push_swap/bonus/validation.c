/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:35:31 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/13 20:46:17 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	validation_data(int argc, t_data *data)
{
	if (argc < 2 || data->stack_a->count == 0)
		normal_exit(data);
	duplicate_validation(data);
}
