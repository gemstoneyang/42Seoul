/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 18:38:52 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	parse_nums(argc, argv, data);
	/** printf("parse finish\n"); */
	validation_data(argc, data);
	/** printf("validation finish\n"); */
	a_to_b(data, data->stack_a->count);
	/** printf("swap finish\n"); */
	cmd_optimization(data);
	/** printf("optimization finish\n"); */
	print_cmd(data);
	/** printf("print cmd finish\n"); */
	normal_exit(data);
	return (0);
}
