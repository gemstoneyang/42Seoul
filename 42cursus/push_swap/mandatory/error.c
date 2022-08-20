/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:29:16 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 02:31:51 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*list;

	list = data->cmd_list;
	if (data->stack_a)
		free_stack(data->stack_a);
	if (data->stack_b)
		free_stack(data->stack_b);
	if (list)
		ft_lstclear(&list, free);
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
