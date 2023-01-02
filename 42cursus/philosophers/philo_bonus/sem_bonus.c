/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:19:14 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/02 11:24:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*init_sem(const char *sem_name, int n)
{
	sem_t	*sem;

	sem_unlink(sem_name);
	sem = sem_open(sem_name, O_CREAT, 0644, n);
	if (sem == SEM_FAILED)
		error_exit("sem_open fail");
	sem_unlink(sem_name);
	return (sem);
}

void	ft_sem_wait(sem_t *sem)
{
	if (sem_wait(sem) != 0)
		error_exit("sem_wait fail");
}

void	ft_sem_post(sem_t *sem)
{
	if (sem_post(sem) != 0)
		error_exit("sem_post fail");
}
