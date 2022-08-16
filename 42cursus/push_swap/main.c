/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/16 21:30:11 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init
	parse_nums(argc, argv, data);
	t_node	*head = stack_a->top;
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
	normal_exit(data);
	return (0);
}
