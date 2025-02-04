/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:04:02 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/30 20:26:46 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

pthread_mutex_t	*init_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		return (NULL);
	}
	return (mutex);
}

int	ft_mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	return (0);
}

int	ft_mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (0);
}

int	ft_mutex_destroy_free(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		return (1);
	free(mutex);
	return (0);
}

int	update_error(t_info *info, int error)
{
	if (!error)
		return (0);
	pthread_mutex_lock(info->error_mutex);
	info->error = 1;
	pthread_mutex_unlock(info->error_mutex);
	return (1);
}
