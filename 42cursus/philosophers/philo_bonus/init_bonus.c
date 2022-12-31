/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:41:27 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/31 15:15:58 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

static t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->is_dead = 0;
	info->start_time = get_time();
	info->dead_mutex = init_mutex();
	if (info->start_time == 0 || !info->dead_mutex)
	{
		free(info);
		return (NULL);
	}
	info->error_mutex = init_mutex();
	if (!info->error_mutex)
	{
		ft_mutex_destroy_free(info->dead_mutex);
		free(info);
		return (NULL);
	}
	if (parse_info(info, argc, argv) == -1)
		return (NULL);
	return (info);
}

static t_fork	*init_fork_arr(int n)
{
	t_fork	*fork_arr;
	int		i;
	int		error;

	fork_arr = (t_fork *)malloc(sizeof(t_fork) * (n + 1));
	if (!fork_arr)
		return (NULL);
	error = 0;
	i = 0;
	while (++i < n + 1)
	{
		fork_arr[i].status = 1;
		fork_arr[i].mutex = init_mutex();
		if (!(fork_arr[i].mutex))
			error = 1;
	}
	if (!error)
		return (fork_arr);
	while (--i > 0)
	{
		if (fork_arr[i].mutex)
			ft_mutex_destroy_free(fork_arr[i].mutex);
	}
	free(fork_arr);
	return (NULL);
}

static int	init_philo(t_philo *philo, t_info *info, t_fork *fork_arr, int i)
{
	philo->id = i;
	philo->eat_count = 0;
	philo->count_mutex = init_mutex();
	philo->time_mutex = init_mutex();
	if (!philo->count_mutex || !philo->time_mutex)
	{
		if (philo->count_mutex)
			ft_mutex_destroy_free(philo->count_mutex);
		if (philo->time_mutex)
			ft_mutex_destroy_free(philo->time_mutex);
		return (-1);
	}
	philo->left_fork = fork_arr + i;
	philo->right_fork = fork_arr + (i % info->philo_num + 1);
	philo->info = info;
	return (0);
}

static t_philo	*init_philo_arr(t_info *info, t_fork *fork_arr)
{
	t_philo		*philo_arr;
	int			i;
	u_int64_t	start_time;

	philo_arr = (t_philo *)malloc(sizeof(t_philo) * (info->philo_num + 1));
	if (!philo_arr)
		return (NULL);
	start_time = get_time();
	if (start_time == 0)
	{
		free(philo_arr);
		return (NULL);
	}
	i = 1;
	while (i < info->philo_num + 1)
	{
		philo_arr[i].last_eat_time = start_time;
		if (init_philo(philo_arr + i, info, fork_arr, i) == -1)
			free_philo_arr(philo_arr, i);
		i++;
	}
	return (philo_arr);
}

int	init_arg(t_arg *arg, int argc, char **argv)
{
	arg->info = NULL;
	arg->fork_arr = NULL;
	arg->philo_arr = NULL;
	arg->error = 1;
	arg->info = init_info(argc, argv);
	if (!arg->info)
		return (-1);
	arg->fork_arr = init_fork_arr(arg->info->philo_num);
	if (!arg->fork_arr)
		return (-1);
	arg->philo_arr = init_philo_arr(arg->info, arg->fork_arr);
	if (!arg->philo_arr)
		return (-1);
	arg->error = 0;
	return (0);
}
