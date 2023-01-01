/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:08:03 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 15:45:25 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo_bonus.h"

int	print_log(t_philo *philo, char *msg)
{
	uint64_t		diff_time;
	uint64_t		now_time;

	sem_wait(philo->info->print_sem);
	now_time = get_time();
	diff_time = (now_time - philo->info->start_time) / 1000;
	printf("%llu %d %s\n", diff_time, philo->id, msg);
	sem_post(philo->info->print_sem);
	return (0);
}
