/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:21:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/31 15:15:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

int	free_philo_arr(t_philo *philo_arr, int n)
{
	int	i;
	int	error;

	error = 0;
	i = 1;
	while (i < n)
	{
		error += ft_mutex_destroy_free(philo_arr[i].count_mutex);
		error += ft_mutex_destroy_free(philo_arr[i].time_mutex);
		i++;
	}
	free(philo_arr);
	return (error);
}

int	free_arg(t_arg *arg)
{
	int	i;

	if (!arg->info)
		return (1);
	if (arg->fork_arr)
	{
		i = 0;
		while (++i < arg->info->philo_num + 1)
			arg->error = ft_mutex_destroy_free(arg->fork_arr[i].mutex);
		free(arg->fork_arr);
	}
	if (arg->philo_arr)
		free_philo_arr(arg->philo_arr, arg->info->philo_num + 1);
	arg->error = ft_mutex_destroy_free(arg->info->dead_mutex);
	arg->error = ft_mutex_destroy_free(arg->info->error_mutex);
	free(arg->info);
	return (arg->error);
}
