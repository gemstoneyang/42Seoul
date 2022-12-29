/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 22:23:03 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	print_log(t_philo *philo, uint64_t time, char *msg, int color)
{
	pthread_mutex_t	*print_mutex;

	print_mutex = philo->info->print_mutex;
	pthread_mutex_lock(print_mutex);
	printf("\033[0;3%dm", color);
	pass_time(philo->info->start_time, time);
	printf(" %d %s\n\033[0m", philo->id, msg);
	pthread_mutex_unlock(print_mutex);
}
