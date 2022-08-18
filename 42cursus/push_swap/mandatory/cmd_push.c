/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:12:31 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 22:17:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_push(t_data *data)
{
	t_node	*node;

	node = pop(data->stack_b);
	push(data->stack_a, node);
}

void	pa(t_data *data)
{
	write(1, "pa\n", 3);
	if (data->stack_b->count == 0)
		return ;
	cmd_push(data);
}

void	pb(t_data *data)
{
	write(1, "pb\n", 3);
	if (data->stack_a->count == 0)
		return ;
	cmd_push(data);
}
