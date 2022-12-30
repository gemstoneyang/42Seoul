/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:21:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 16:30:59 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
	if (info->start_time == 0)
	{
		free(info);
		return (NULL);
	}
	info->dead_mutex = init_mutex();
	if (!info->dead_mutex)
	{
		free(info);
		return (NULL);
	}
	if (parse_argument(info, argc, argv) == -1)
	{
		pthread_mutex_destroy(info->dead_mutex);
		free(info);
		return (NULL);
	}
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
			pthread_mutex_destroy(fork_arr[i].mutex);
	}
	free(fork_arr);
	return (NULL);
}

int	free_philo_arr(t_philo *philo_arr, int n)
{
	int	i;
	int	error;

	error = 0;
	i = 1;
	while (i < n)
	{
		if (pthread_mutex_destroy(philo_arr[i].count_mutex) != 0)
			error = 1;
		if (pthread_mutex_destroy(philo_arr[i].time_mutex) != 0)
			error = 1;
		free(philo_arr[i].count_mutex);
		free(philo_arr[i].time_mutex);
		i++;
	}
	free(philo_arr);
	return (error);
}

static t_philo	*init_philo_arr(t_info *info, t_fork *fork_arr)
{
	t_philo	*philo_arr;
	int		i;
	int		n;
	u_int64_t	start_time;

	n = info->philo_num;
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * (n + 1));
	if (!philo_arr)
		return (NULL);
	start_time = get_time();
	if (start_time == 0)
	{
		free(philo_arr);
		return (NULL);
	}
	i = 1;
	while (i < n + 1)
	{
		philo_arr[i].id = i;
		philo_arr[i].eat_count = 0;
		philo_arr[i].last_eat_time = start_time;
		philo_arr[i].count_mutex = init_mutex();
		philo_arr[i].time_mutex = init_mutex();
		if (!philo_arr[i].count_mutex || !philo_arr[i].time_mutex)
		{
			if (philo_arr[i].count_mutex)
				pthread_mutex_destroy(philo_arr[i].count_mutex);
			if (philo_arr[i].count_mutex)
				pthread_mutex_destroy(philo_arr[i].count_mutex);
			free_philo_arr(philo_arr, i);
			return (NULL);
		}
		philo_arr[i].left_fork = fork_arr + i;
		philo_arr[i].right_fork = fork_arr + (i % n + 1);
		philo_arr[i].info = info;
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

int	free_arg(t_arg *arg)
{
	int	i;

	if (!arg->info)
		return (1);
	i = 1;
	if (arg->fork_arr)
	{
		while (i < arg->info->philo_num + 1)
		{
			if (pthread_mutex_destroy(arg->fork_arr[i].mutex) != 0)
				arg->error = 1;
			free(arg->fork_arr[i].mutex);
			i++;
		}
		free(arg->fork_arr);
	}
	if (arg->philo_arr)
		free_philo_arr(arg->philo_arr, arg->info->philo_num + 1);
	if (pthread_mutex_destroy(arg->info->dead_mutex) != 0)
		arg->error = 1;
	free(arg->info->dead_mutex);
	free(arg->info);
	return (arg->error);
}
