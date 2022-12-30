/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 21:15:03 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	msleep(uint64_t msec)
{
	uint64_t	start_time;
	uint64_t	now_time;

	start_time = get_time();
	now_time = get_time();
	if (start_time == 0 || now_time == 0)
		return (1);
	while (start_time + msec * 1000 > now_time)
	{
		if (usleep(1000) != 0)
			return (1);
		now_time = get_time();
		if (now_time == 0)
			return (1);
	}
	return (0);
}
