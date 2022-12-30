/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 10:05:36 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_t	*print_mutex;
	uint64_t		diff_time;

	print_mutex = philo->info->print_mutex;
	pthread_mutex_lock(print_mutex);
	diff_time = (get_time() - philo->info->start_time) / 1000;
	printf("%llu %d %s\n", diff_time, philo->id, msg);
	pthread_mutex_unlock(print_mutex);
}
