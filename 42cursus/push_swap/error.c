/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:29:16 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/16 20:51:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		free(node);
		node = node->next;
	}
	free(stack);
	return ;
}

void	free_data(t_data *data)
{
	if (data->stack_a)
		free_stack(stack_a);
	if (data->stack_b)
		free_stack(stack_b);
	free(data);
}

void	error_exit(t_data *data)
{
	if (data)
		free_data(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	normal_exit(t_data *data)
{
	if (data)
		free_data(data);
	exit(0);
}
