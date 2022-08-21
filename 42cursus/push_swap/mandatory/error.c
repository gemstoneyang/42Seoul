/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:29:16 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 14:45:24 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_list	*now;
	t_list	*nxt;

	now = list;
	nxt = now->next;
	while (nxt)
	{
		free(now);
		now = nxt;
		nxt = now->next;
	}
	free(now);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	tmp = node;
	while (node)
	{
		node = node->next;
		free(tmp);
		tmp = node;
	}
	free(stack);
	return ;
}

void	free_data(t_data *data)
{
	if (data->stack_a)
		free_stack(data->stack_a);
	if (data->stack_b)
		free_stack(data->stack_b);
	if (data->cmd_list)
		free_list(data->cmd_list);
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
