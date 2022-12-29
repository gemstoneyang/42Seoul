/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:21:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 16:18:49 by wonyang          ###   ########seoul.kr  */
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

static t_fork	*init_fork_arr(int n)
{
	t_fork	*fork_arr;
	int		i;
	int		error;

	fork_arr = (t_fork *)malloc(sizeof(t_fork) * (n + 1));
	if (!fork_arr)
		return (NULL);
	error = 0;
	i = 1;
	while (i < n + 1)
	{
		fork_arr[i].status = 1;
		fork_arr[i].mutex = init_mutex();
		if (!(fork_arr[i].mutex))
			error = 1;
		i++;
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

static t_philo	*init_philo_arr(t_info *info, t_fork *fork_arr)
{
	t_philo	*philo_arr;
	int		i;
	int		n;

	n = info->philo_num;
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * (n + 1));
	if (!philo_arr)
		return (NULL);
	i = 1;
	while (i < n + 1)
	{
		philo_arr[i].id = i;
		philo_arr[i].last_eat_time = get_time();
		if (philo_arr[i].last_eat_time == 0)
		{
			free(philo_arr);
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
	if (arg->philo_arr)
		free(arg->philo_arr);
	i = 1;
	if (arg->fork_arr)
	{
		while (i < arg->info->philo_num)
		{
			if(pthread_mutex_destroy(arg->fork_arr[i].mutex) != 0)
				arg->error = 1;
			i++;
		}
		free(arg->fork_arr);
	}
	if (pthread_mutex_destroy(arg->info->print_mutex) != 0)
		arg->error = 1;
	free(arg->info);
	return (1);
}
