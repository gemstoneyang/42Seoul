/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:21:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 15:31:29 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

static t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->is_dead = 0;
	info->start_time = get_time();
	info->print_mutex = init_mutex();
	if (info->start_time == 0 || !info->print_mutex)
	{
		free(info);
		return (NULL);
	}
	if (parse_argument(info, argc, argv) == -1)
		return (NULL);
	return (info);
}

int	init_arg(t_arg *arg, int argc, char **argv)
{
	arg->info = NULL;
	arg->fork_arr = NULL;
	arg->philo_arr = NULL;
	arg->info = init_info(argc, argv);
	if (!arg->info)
		return (-1);
	arg->fork_arr = init_fork_arr(arg->info->philo_num);
	arg->philo_arr = init_philo_arr(arg->info, arg->fork_arr);
	return (0);
}

// int	free_arg(t_arg *arg)
// {
// 	return (1);
// }
