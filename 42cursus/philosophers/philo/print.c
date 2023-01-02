/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:03 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/02 11:30:04 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_t	*dead_mutex;
	uint64_t		diff_time;
	uint64_t		now_time;
	int				error;

	error = 0;
	dead_mutex = philo->info->dead_mutex;
	if (pthread_mutex_lock(dead_mutex) != 0)
		error += 1;
	if (philo->info->is_dead)
	{
		if (pthread_mutex_unlock(dead_mutex) != 0)
			error += 1;
		return (error);
	}
	now_time = get_time();
	if (now_time == 0)
		error += 1;
	diff_time = (now_time - philo->info->start_time) / 1000;
	printf("%llu %d %s\n", diff_time, philo->id, msg);
	if (pthread_mutex_unlock(dead_mutex) != 0)
		error += 1;
	return (error);
}
