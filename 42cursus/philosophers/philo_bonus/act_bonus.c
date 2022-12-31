/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/31 15:15:22 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_take_fork(t_philo *philo, t_fork *fork, int *error)
{
	*error += ft_mutex_lock(fork->mutex);
	fork->status = 0;
	*error += print_log(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo, int *error)
{
	*error += ft_mutex_lock(philo->time_mutex);
	philo->last_eat_time = get_time();
	if (philo->last_eat_time == 0)
		*error += 1;
	*error += ft_mutex_unlock(philo->time_mutex);
	*error += print_log(philo, "is eating");
	*error += msleep(philo->info->eat_time);
	*error += ft_mutex_lock(philo->count_mutex);
	philo->eat_count += 1;
	*error += ft_mutex_unlock(philo->count_mutex);
}

void	philo_put_down_fork(t_fork *fork, int *error)
{
	fork->status = 1;
	*error += ft_mutex_unlock(fork->mutex);
}

void	philo_sleep(t_philo *philo, int *error)
{
	if (philo->info->philo_num == 1)
		return ;
	*error += print_log(philo, "is sleeping");
	*error += msleep(philo->info->sleep_time);
}

void	philo_think(t_philo *philo, int *error)
{
	if (philo->info->philo_num == 1)
		return ;
	*error += print_log(philo, "is thinking");
}
