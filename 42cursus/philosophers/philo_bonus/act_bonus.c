/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 19:18:40 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_take_fork(t_philo *philo)
{
	sem_wait(philo->info->fork_sem);
	print_log(philo, "has taken a fork");
	sem_wait(philo->info->fork_sem);
	print_log(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->time_sem);
	philo->last_eat_time = get_time();
	sem_post(philo->time_sem);
	print_log(philo, "is eating");
	msleep(philo->info->eat_time);
	philo->eat_count += 1;
	if (philo->eat_count == philo->info->eat_num)
		sem_post(philo->info->eat_sem);
}

void	philo_put_down_fork(t_philo *philo)
{
	sem_post(philo->info->fork_sem);
	sem_post(philo->info->fork_sem);
}

void	philo_sleep(t_philo *philo)
{
	print_log(philo, "is sleeping");
	msleep(philo->info->sleep_time);
}

void	philo_think(t_philo *philo)
{
	print_log(philo, "is thinking");
}
