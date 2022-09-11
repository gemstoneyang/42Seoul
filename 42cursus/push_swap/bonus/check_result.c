/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:12:11 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/11 23:11:43 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool	is_sorted(t_data *data)
{
	t_node	*node;

	node = data->stack_a->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

void	check_result(t_data *data)
{
	if (is_sorted(data) == FALSE || data->stack_b->count != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	normal_exit(data);
}
