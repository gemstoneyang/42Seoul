/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/27 19:49:50 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pass_time(philo->arg->start_time);
		printf(" no.%d is running\n", philo->id);
		usleep(500 * 1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info		info;
	t_arg		arg;
	t_fork		*fork_arr;
	t_philo		*philo_arr;

	if (argc != 5 && argc != 6)
	{
		printf("argument count error\n");
		return (1);
	}
	if (parse_argument(&info, argc, argv) == -1)
	{
		printf("argument infomation error\n");
		return (1);
	}

	arg.dead = 0;
	arg.start_time = get_time();
	fork_arr = init_fork_arr(info.philo_num);
	philo_arr = init_philo_arr(&arg, fork_arr, info.philo_num);
	for (int i = 1; i < info.philo_num + 1; i++)
		pthread_create(&(philo_arr[i].thread), NULL, philo_thread, philo_arr + i);
	for (int i = 1; i < info.philo_num + 1; i++)
		pthread_join(philo_arr[i].thread, NULL);

	return (0);
}
