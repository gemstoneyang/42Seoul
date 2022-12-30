/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 17:49:56 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	int		error;

	error = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		error += msleep(1);
	while (1)
	{
		philo_take_fork(philo, philo->left_fork, &error);
		philo_take_fork(philo, philo->right_fork, &error);
		philo_eat(philo, &error);
		philo_put_down_fork(philo->right_fork, &error);
		philo_put_down_fork(philo->left_fork, &error);
		error += ft_mutex_lock(philo->info->dead_mutex);
		if (philo->info->is_dead)
		{
			error += ft_mutex_unlock(philo->info->dead_mutex);
			break ;
		}
		error += ft_mutex_unlock(philo->info->dead_mutex);
		philo_sleep(philo, &error);
		philo_think(philo, &error);
		if (error)
		{
			pthread_mutex_lock(philo->info->error_mutex);
			philo->info->error = 1;
			pthread_mutex_unlock(philo->info->error_mutex);
			break ;
		}
	}
	return (NULL);
}

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
	return (free_arg(&arg));
}
