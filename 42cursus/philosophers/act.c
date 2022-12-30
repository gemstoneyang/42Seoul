/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 13:58:05 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->mutex);
	fork->status = 0;
	return (print_log(philo, "has taken a fork"));
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->time_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(philo->time_mutex);
	if (print_log(philo, "is eating") == 1)
		return (1);
	msleep(philo->info->eat_time);
	pthread_mutex_lock(philo->count_mutex);
	philo->eat_count += 1;
	pthread_mutex_unlock(philo->count_mutex);
	return (0);
}

int	philo_put_down_fork(t_philo *philo, t_fork *fork)
{
	philo = (t_philo *)philo;
	fork->status = 1;
	pthread_mutex_unlock(fork->mutex);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if(print_log(philo, "is sleeping") == 1)
		return (1);
	msleep(philo->info->sleep_time);
	return (0);
}

int	philo_think(t_philo *philo)
{
	return (print_log(philo, "is thinking"));
}
