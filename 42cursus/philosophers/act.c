/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 16:49:42 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork->mutex);
	philo->left_fork->status = 0;
	print_log(philo, "has taken a fork");

	pthread_mutex_lock(philo->right_fork->mutex);
	philo->right_fork->status = 0;
	print_log(philo, "has taken a fork");

	philo->last_eat_time = get_time();
	
	print_log(philo, "is eating");
	msleep(philo->info->eat_time);

	philo->right_fork->status = 1;
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->left_fork->status = 1;
	pthread_mutex_unlock(philo->left_fork->mutex);

	print_log(philo, "is sleeping");
	msleep(philo->info->sleep_time);
	print_log(philo, "is thinking");
	return (0);
}
