/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:16:33 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/03 18:25:51 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bot = NULL;
	stack->count = 0;
	return (stack);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_exit(data);
	data->stack_a = init_stack();
	data->stack_b = init_stack();
	data->cmd_list = ft_lstnew(NULL);
	if (!(data->stack_a) || !(data->stack_b) || !(data->cmd_list))
		error_exit(data);
	return (data);
}
