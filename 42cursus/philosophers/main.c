/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 13:55:55 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		msleep(500);
	while (1)
	{
		print_log(philo, "is running");
		msleep(1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info		info;
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
	init_info(&info);
	
	fork_arr = init_fork_arr(info.philo_num);
	philo_arr = init_philo_arr(&info, fork_arr, info.philo_num);
	for (int i = 1; i < info.philo_num + 1; i++)
		pthread_create(&(philo_arr[i].thread), NULL, philo_thread, philo_arr + i);
	for (int i = 1; i < info.philo_num + 1; i++)
		pthread_join(philo_arr[i].thread, NULL);

	return (0);
}
