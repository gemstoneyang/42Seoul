/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:41:27 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 15:58:45 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

t_philo	*init_philo_arr(t_info *info, t_fork *fork_arr)
{
	t_philo	*philo_arr;
	int		i;
	int		n;

	n = info->philo_num;
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * (n + 1));
	i = 1;
	while (i < n + 1)
	{
		philo_arr[i].id = i;
		philo_arr[i].last_eat_time = get_time();
		philo_arr[i].left_fork = fork_arr + i;
		philo_arr[i].right_fork = fork_arr + (i % n + 1);
		philo_arr[i].info = info;
		i++;
	}
	return (philo_arr);
}

pthread_mutex_t	*init_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		return (NULL);
	}
	return (mutex);
}
