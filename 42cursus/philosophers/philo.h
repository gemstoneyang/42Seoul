/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/26 21:01:09 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>

typedef struct s_info
{
	int	philo_num;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
}	t_info;

typedef struct s_philo
{
	int				num;
	t_info			info;
	struct timeval	last_eat;
}	t_philo;

// libft.c
int	ft_atoi(const char *str);

// ft_isinteger.c
int	ft_isinteger(char *str);

// parse.c
int	parse_argument(t_info *info, int argc, char **argv);

#endif
