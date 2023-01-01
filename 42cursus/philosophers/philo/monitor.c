/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:19 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 16:22:25 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

static int	check_eat_count(t_philo *philo_arr, t_info *info, int *error)
{
	int	i;

	i = 1;
	while (i < info->philo_num + 1)
	{
		error += ft_mutex_lock(philo_arr[i].count_mutex);
		if (philo_arr[i].eat_count < info->eat_num)
		{
			error += ft_mutex_unlock(philo_arr[i].count_mutex);
			return (0);
		}
		error += ft_mutex_unlock(philo_arr[i].count_mutex);
		i++;
	}
	return (1);
}

static int	update_dead(t_philo *philo, t_info *info, uint64_t now, int *error)
{
	uint64_t	diff;

	*error += ft_mutex_lock(philo->time_mutex);
	if ((int)(now - philo->last_eat_time) >= info->life_time * 1000)
	{
		*error += ft_mutex_lock(info->dead_mutex);
		info->is_dead = 1;
		diff = (now - info->start_time) / 1000;
		if (printf("%llu %d %s\n", diff, philo->id, "died") == -1)
			*error += 1;
		*error += ft_mutex_unlock(info->dead_mutex);
		*error += ft_mutex_unlock(philo->time_mutex);
		return (1);
	}
	*error += ft_mutex_unlock(philo->time_mutex);
	return (0);
}

static int	check_philo_dead(t_philo *philo_arr, t_info *info, int *error)
{
	uint64_t	now_time;
	int			i;

	now_time = get_time();
	if (now_time == 0)
		*error += 1;
	i = 0;
	while (++i < info->philo_num + 1)
	{
		if (update_dead(philo_arr + i, info, now_time, error) == 1)
			return (1);
	}
	return (0);
}

static int	check_error(t_info *info, int *error)
{
	error += ft_mutex_lock(info->error_mutex);
	error += info->error;
	error += ft_mutex_unlock(info->error_mutex);
	return (*error);
}

void	monitoring(t_arg *arg)
{
	int	error;

	error = 0;
	while (!error)
	{
		if (check_error(arg->info, &error) != 0)
			break ;
		if (arg->info->eat_num != -1 && \
			check_eat_count(arg->philo_arr, arg->info, &error) == 1)
			break ;
		if (check_philo_dead(arg->philo_arr, arg->info, &error) == 1)
			break ;
		if (usleep(50) != 0)
			error += 1;
	}
	pthread_mutex_lock(arg->info->dead_mutex);
	arg->info->is_dead = 1;
	pthread_mutex_unlock(arg->info->dead_mutex);
	if (error)
		arg->error = 1;
}
