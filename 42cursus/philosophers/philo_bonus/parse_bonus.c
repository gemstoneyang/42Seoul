/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:52:02 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/31 15:16:20 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	string_to_integer(char *str)
{
	if (!ft_isinteger(str))
		return (-1);
	return (ft_atoi(str));
}

static int	parse_argument(t_info *info, int argc, char **argv)
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

int	parse_info(t_info *info, int argc, char **argv)
{
	if (parse_argument(info, argc, argv) != -1)
		return (0);
	ft_mutex_destroy_free(info->error_mutex);
	ft_mutex_destroy_free(info->dead_mutex);
	free(info);
	return (-1);
}
