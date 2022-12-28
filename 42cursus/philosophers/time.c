/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/28 12:06:16 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

t_ull	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	pass_time(t_ull start_time)
{
	t_ull	now_time;

	now_time = get_time();
	printf("%llu", (now_time - start_time) / 1000);
}

void	msleep(unsigned int msec)
{
	t_ull	start_time;
	t_ull	now_time;

	start_time = get_time();
	now_time = get_time();
	while (start_time + msec * 1000 > now_time)
	{
		usleep(50);
		now_time = get_time();
	}
}
