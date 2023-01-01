/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:21:38 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 19:32:29 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "philo_bonus.h"

void	free_arg(t_arg *arg)
{
	int	i;

	i = 1;
	while (i < arg->info->philo_num + 1)
	{
		kill(arg->philo_arr[i].pid, SIGINT);
		i++;
	}
	free(arg->philo_arr);
	free(arg->info);
	return ;
}
