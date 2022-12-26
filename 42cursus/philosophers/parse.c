/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:52:02 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/26 20:59:40 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	string_to_integer(char *str)
{
	if (!ft_isinteger(str))
		return (-1);
	return (ft_atoi(str));
}

int	parse_argument(t_info *info, int argc, char **argv)
{
	info->philo_num = string_to_integer(argv[1]);
	if (info->philo_num < 1)
		return (-1);
	info->life_time = string_to_integer(argv[2]);
	if (info->life_time < 0)
		return (-1);
	info->eat_time = string_to_integer(argv[3]);
	if (info->eat_time < 0)
		return (-1);
	info->sleep_time = string_to_integer(argv[4]);
	if (info->sleep_time < 0)
		return (-1);
	if (argc == 6)
	{
		info->eat_num = string_to_integer(argv[5]);
		if (info->eat_num < 0)
			return (-1);
	}
	else
		info->eat_num = -1;
	return (0);
}
