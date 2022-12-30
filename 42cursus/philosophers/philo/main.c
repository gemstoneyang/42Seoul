/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 21:30:43 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_act(t_philo *philo, int *error)
{
	philo_take_fork(philo, philo->left_fork, error);
	if (philo->info->philo_num != 1)
	{
		philo_take_fork(philo, philo->right_fork, error);
		philo_eat(philo, error);
		philo_put_down_fork(philo->right_fork, error);
	}
	philo_put_down_fork(philo->left_fork, error);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		error;

	error = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		error += msleep(1);
	while (1)
	{
		philo_act(philo, &error);
		error += ft_mutex_lock(philo->info->dead_mutex);
		if (philo->info->philo_num == 1 || philo->info->is_dead)
		{
			error += ft_mutex_unlock(philo->info->dead_mutex);
			break ;
		}
		error += ft_mutex_unlock(philo->info->dead_mutex);
		philo_sleep(philo, &error);
		philo_think(philo, &error);
		if (update_error(philo->info, error))
			break ;
	}
	return (NULL);
}

static void	run_threads(t_philo *philo_arr, t_info *info)
{
	pthread_t	*th;
	int			i;
	int			error;

	i = 1;
	error = 0;
	while (i < info->philo_num + 1)
	{
		th = &(philo_arr[i].thread);
		if (pthread_create(th, NULL, routine, philo_arr + i) != 0)
			error++;
		i++;
	}
	update_error(info, error);
}

static void	catch_threads(t_philo *philo_arr, t_info *info)
{
	pthread_t	th;
	int			i;
	int			error;

	i = 1;
	error = 0;
	while (i < info->philo_num + 1)
	{
		th = philo_arr[i].thread;
		if (pthread_join(th, NULL) != 0)
			error++;
		i++;
	}
	update_error(info, error);
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 5 && argc != 6)
		return (1);
	if (init_arg(&arg, argc, argv) == -1)
		return (free_arg(&arg));
	run_threads(arg.philo_arr, arg.info);
	monitoring(&arg);
	catch_threads(arg.philo_arr, arg.info);
	return (free_arg(&arg));
}
