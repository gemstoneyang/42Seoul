/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:12:31 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/04 21:39:02 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node	*node;

	if (data->stack_b->count == 0)
		return ;
	node = pop(data->stack_b);
	push(data->stack_a, node);
}

void	pb(t_data *data)
{
	t_node	*node;

	if (data->stack_a->count == 0)
		return ;
	node = pop(data->stack_a);
	push(data->stack_b, node);
}
