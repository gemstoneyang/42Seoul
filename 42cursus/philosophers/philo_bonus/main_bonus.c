/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 20:38:30 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo_bonus.h"

static void	*monitor_dead(void *arg)
{
	t_philo		*philo;
	t_info		*info;
	uint64_t	now_diff;
	uint64_t	diff;

	philo = (t_philo *)arg;
	info = philo->info;
	while (1)
	{
		sem_wait(philo->time_sem);
		now_diff = get_time() - philo->last_eat_time;
		sem_post(philo->time_sem);
		if ((int)(now_diff) >= info->life_time * 1000)
		{
			sem_wait(info->print_sem);
			diff = (get_time() - info->start_time) / 1000;
			printf("%llu %d %s\n", diff, philo->id, "died");
			sem_post(info->end_sem);
			return (NULL);
		}
		msleep(5);
	}
	return (NULL);
}

static void	child_process(t_philo *philo)
{
	pthread_t	thread;
	char		*sem_name;

	sem_name = ft_itoa(philo->id);
	if (!sem_name)
		sem_post(philo->info->end_sem);
	philo->time_sem = init_sem(sem_name, 1);
	free(sem_name);
	if (pthread_create(&thread, NULL, monitor_dead, (void *)philo) != 0
		|| pthread_detach(thread) != 0)
		sem_post(philo->info->end_sem);
	if (philo->id % 2 == 0)
		msleep(10);
	while (1)
	{
		philo_take_fork(philo);
		philo_eat(philo);
		philo_put_down_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

static void	*monitor_eat(void *arg)
{
	t_info	*info;
	int		count;

	info = (t_info *)arg;
	count = 0;
	while (count < info->philo_num)
	{
		sem_wait(info->eat_sem);
		count++;
	}
	sem_wait(info->print_sem);
	sem_post(info->end_sem);
	return (NULL);
}

static void	run_philos(t_philo *philo_arr, t_info *info)
{
	int			i;
	pthread_t	thread;

	if (pthread_create(&thread, NULL, monitor_eat, (void *)info) != 0
		|| pthread_detach(thread) != 0)
		error_exit("pthread fail");
	i = 1;
	while (i < info->philo_num + 1)
	{
		philo_arr[i].pid = ft_fork();
		if (philo_arr[i].pid == 0)
		{
			child_process(philo_arr + i);
			exit(0);
		}
		i++;
	}
	sem_wait(info->end_sem);
	return ;
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	init_arg(&arg, argc, argv);
	run_philos(arg.philo_arr, arg.info);
	free_arg(&arg);
	return (0);
}
