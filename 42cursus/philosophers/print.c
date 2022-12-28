/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/28 11:38:42 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	print_log(t_philo *philo, char *msg)
{
	pthread_mutex_t	*print_mutex;

	print_mutex = &(philo->info->print_mutex);
	pthread_mutex_lock(print_mutex);
	pass_time(philo->info->start_time);
	printf(" no.%d %s\n", philo->id, msg);
	pthread_mutex_unlock(print_mutex);
}
