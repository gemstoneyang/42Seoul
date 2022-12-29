/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 21:21:39 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork->mutex);
	fork->status = 0;
	print_log(philo, get_time(), "has taken a fork");
	return (0);
}

int	philo_eat(t_philo *philo)
{
	philo->last_eat_time = get_time(); // add mutex
	philo->eat_count += 1; // add mutex
	print_log(philo, philo->last_eat_time, "is eating");
	msleep(philo->info->eat_time);
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
	print_log(philo, get_time(), "is sleeping");
	msleep(philo->info->sleep_time);
	return (0);
}

int	philo_think(t_philo *philo)
{
	print_log(philo, get_time(), "is thinking");
	return (0);
}
