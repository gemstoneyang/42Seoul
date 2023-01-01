/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:04:02 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 17:24:24 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

sem_t	*init_sem(const char *sem_name, int n)
{
	sem_t	*sem;

	sem = (sem_t *)ft_malloc(sizeof(sem_t));
	sem = sem_open(sem_name, O_CREAT, 0644, n);
	if (sem == SEM_FAILED)
		error_exit("sem_open fail");
	if (sem_unlink(sem_name) != 0)
		error_exit("sem_unlink fail");
	return (sem);
}
