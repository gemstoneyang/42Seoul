/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/26 22:21:51 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"

void	*philo_func(t_info *info)
{

}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	*philo_arr;
	int			*fork_arr;

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
	philo_arr = (pthread_t *)malloc(sizeof(pthread_t) * (info.philo_num + 1));
	fork_arr = (int *)malloc(sizeof(int) * (info.philo_num + 1));
	int	i;
	i = 1;
	while (i < info.philo_num + 1)
	{
		pthread_create(philo_arr + i, NULL, philo_func, &info);
		fork_arr[i] = 1;
		i++;
	}

	pthread_create(th)

	return (0);
}
