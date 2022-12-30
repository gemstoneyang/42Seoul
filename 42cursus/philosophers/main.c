/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 16:30:59 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		msleep(1);
	while (1)
	{
		philo_take_fork(philo, philo->left_fork);
		philo_take_fork(philo, philo->right_fork);
		philo_eat(philo);
		philo_put_down_fork(philo, philo->right_fork);
		philo_put_down_fork(philo, philo->left_fork);
		pthread_mutex_lock(philo->info->dead_mutex);
		if (philo->info->is_dead)
		{
			pthread_mutex_unlock(philo->info->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->info->dead_mutex);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
#include <unistd.h>
int	main(int argc, char **argv)
{
	t_arg		arg;
	t_info		*info;
	t_fork		*fork_arr;
	t_philo		*philo_arr;

	if (argc != 5 && argc != 6)
		return (1);
	if (init_arg(&arg, argc, argv) == -1)
		return (free_arg(&arg));

	info = arg.info;
	fork_arr = arg.fork_arr;
	philo_arr = arg.philo_arr;

	for (int i = 1; i < info->philo_num + 1; i++)
		pthread_create(&(philo_arr[i].thread), NULL, philo_thread, philo_arr + i);
	monitoring(&arg);
	for (int i = 1; i < info->philo_num + 1; i++)
		pthread_join(philo_arr[i].thread, NULL);
	free_arg(&arg);
	return (0);
}
