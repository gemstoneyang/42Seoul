/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:19 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 14:21:41 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static int	check_eat_count(t_philo *philo_arr, t_info *info)
{
	int	i;

	i = 1;
	while (i < info->philo_num + 1)
	{
		pthread_mutex_lock(philo_arr[i].count_mutex);
		if (philo_arr[i].eat_count < info->eat_num)
		{
			pthread_mutex_unlock(philo_arr[i].count_mutex);
			return (0);
		}
		pthread_mutex_unlock(philo_arr[i].count_mutex);
		i++;
	}
	return (1);
}

static int	check_philo_dead(t_philo *philo_arr, t_info *info)
{
	uint64_t	now_time;
	int	i;
	t_philo		philo;

	i = 1;
	now_time = get_time();
	while (i < info->philo_num + 1)
	{
		philo = philo_arr[i];
		pthread_mutex_lock(philo.time_mutex);
		if ((int)(now_time - philo.last_eat_time) > info->life_time * 1000)
		{
			pthread_mutex_lock(info->dead_mutex);
			info->is_dead = 1;
			printf("\033[0;3%dm", 1);
			pass_time(info->start_time);
			printf(" %d %s\n\033[0m", philo.id, "died");
			pthread_mutex_unlock(info->dead_mutex);
			pthread_mutex_unlock(philo.time_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo.time_mutex);
		i++;
	}
	return (0);
}
#include <unistd.h>
void	monitoring(t_arg *arg)
{
	while (1)
	{
		if (arg->info->eat_num != -1 && check_eat_count(arg->philo_arr, arg->info) == 1)
			break ;
		if (check_philo_dead(arg->philo_arr, arg->info) == 1)
			break ;
		usleep(50);
	}
	pthread_mutex_lock(arg->info->dead_mutex);
	arg->info->is_dead = 1;
	pthread_mutex_unlock(arg->info->dead_mutex);
}
