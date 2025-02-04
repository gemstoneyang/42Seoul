/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:41:27 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 20:57:58 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "philo_bonus.h"

static t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)ft_malloc(sizeof(t_info));
	info->start_time = get_time();
	if (parse_argument(info, argc, argv) == -1)
		error_exit("argument error");
	info->fork_sem = init_sem("/fork_sem", info->philo_num);
	info->eat_sem = init_sem("/eat_sem", 0);
	info->end_sem = init_sem("/end_sem", 0);
	info->print_sem = init_sem("print_sem", 1);
	return (info);
}

static int	init_philo(t_philo *philo, t_info *info, int i)
{
	philo->id = i;
	philo->eat_count = 0;
	philo->info = info;
	return (0);
}

static t_philo	*init_philo_arr(t_info *info)
{
	t_philo		*philo_arr;
	int			i;
	u_int64_t	start_time;

	philo_arr = (t_philo *)ft_malloc(sizeof(t_philo) * (info->philo_num + 1));
	start_time = get_time();
	i = 1;
	while (i < info->philo_num + 1)
	{
		philo_arr[i].last_eat_time = start_time;
		init_philo(philo_arr + i, info, i);
		i++;
	}
	return (philo_arr);
}

void	init_arg(t_arg *arg, int argc, char **argv)
{
	arg->info = init_info(argc, argv);
	arg->philo_arr = init_philo_arr(arg->info);
}

void	free_arg(t_arg *arg)
{
	int	i;

	i = 1;
	while (i < arg->info->philo_num + 1)
	{
		kill(arg->philo_arr[i].pid, SIGINT);
		i++;
	}
	free(arg->philo_arr);
	free(arg->info);
	return ;
}
