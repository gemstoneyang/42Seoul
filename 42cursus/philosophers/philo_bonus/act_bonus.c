/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:44 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/02 11:24:59 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_take_fork(t_philo *philo)
{
	ft_sem_wait(philo->info->fork_sem);
	print_log(philo, "has taken a fork");
	ft_sem_wait(philo->info->fork_sem);
	print_log(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	ft_sem_wait(philo->time_sem);
	philo->last_eat_time = get_time();
	ft_sem_post(philo->time_sem);
	print_log(philo, "is eating");
	msleep(philo->info->eat_time);
	philo->eat_count += 1;
	if (philo->eat_count == philo->info->eat_num)
		ft_sem_post(philo->info->eat_sem);
}

void	philo_put_down_fork(t_philo *philo)
{
	ft_sem_post(philo->info->fork_sem);
	ft_sem_post(philo->info->fork_sem);
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
