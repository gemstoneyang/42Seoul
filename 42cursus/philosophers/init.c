/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:41:27 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/28 11:09:51 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

t_fork	*init_fork_arr(int n)
{
	t_fork	*fork_arr;
	int		i;

	fork_arr = (t_fork *)malloc(sizeof(t_fork) * (n + 1));
	i = 1;
	while (i < n + 1)
	{
		fork_arr[i].status = 1;
		pthread_mutex_init(&(fork_arr[i].mutex), NULL);
		i++;
	}
	return (fork_arr);
}

t_philo	*init_philo_arr(t_info *info, t_fork *fork_arr, int n)
{
	t_philo	*philo_arr;
	int		i;

	philo_arr = (t_philo *)malloc(sizeof(t_philo) * (n + 1));
	i = 1;
	while (i < n + 1)
	{
		philo_arr[i].id = i;
		philo_arr[i].left_fork = fork_arr + i;
		philo_arr[i].right_fork = fork_arr + (i % n + 1);
		philo_arr[i].info = info;
		i++;
	}
	return (philo_arr);
}

void	init_info(t_info *info)
{
	info->is_dead = 0;
	info->start_time = get_time();
	pthread_mutex_init(&(info->print_mutex), NULL);
}
