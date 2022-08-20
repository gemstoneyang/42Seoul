/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/20 21:15:58 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	parse_nums(argc, argv, data);
	validation_data(argc, data);
	a_to_b(data, data->stack_a->count);
	/** int *arr;  */
	/** arr = stack_to_array(data->stack_a); */
	/** sort_array(arr, data->stack_a->count); */
	/** for (int i = 0; i < data->stack_a->count; i++) */
	/**     printf("%d ", arr[i]); */
	//print_stack(data);
	normal_exit(data);
	return (0);
}
