/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 19:54:10 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	parse_nums(argc, argv, data);
	validation_data(argc, data);
	if (data->stack_a->count == 3)
		sort_only_three_element(data);
	else
		a_to_b(data, data->stack_a->count);
	cmd_optimization(data);
	print_cmd(data);
	normal_exit(data);
	return (0);
}
