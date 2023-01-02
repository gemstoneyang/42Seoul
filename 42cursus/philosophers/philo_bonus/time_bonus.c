/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:46 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/02 11:25:57 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "philo_bonus.h"

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		error_exit("gettimeofday fail");
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_usleep(uint64_t time)
{
	if (usleep(time) != 0)
		error_exit("usleep fail");
}

void	msleep(uint64_t msec)
{
	uint64_t	start_time;
	uint64_t	now_time;

	start_time = get_time();
	now_time = get_time();
	while (start_time + msec * 1000 > now_time)
	{
		ft_usleep(1000);
		now_time = get_time();
	}
}

int	print_log(t_philo *philo, char *msg)
{
	uint64_t		diff_time;
	uint64_t		now_time;

	ft_sem_wait(philo->info->print_sem);
	now_time = get_time();
	diff_time = (now_time - philo->info->start_time) / 1000;
	printf("%llu %d %s\n", diff_time, philo->id, msg);
	ft_sem_post(philo->info->print_sem);
	return (0);
}
