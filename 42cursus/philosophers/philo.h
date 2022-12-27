/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/27 19:42:51 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

typedef unsigned long long	t_ull;

typedef struct s_info
{
	int	philo_num;
	int	life_time;
	int	eat_time;
	int	sleep_time;
	int	eat_num;
}	t_info;

typedef struct s_arg
{
	int		dead;
	t_ull	start_time;
}	t_arg;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	t_arg		*arg;
}	t_philo;

// init.c
t_fork	*init_fork_arr(int n);
t_philo	*init_philo_arr(t_arg *arg, t_fork *fork_arr, int n);

// time.c
t_ull	get_time(void);
void	pass_time(t_ull start_time);

// libft.c
int	ft_atoi(const char *str);

// ft_isinteger.c
int	ft_isinteger(char *str);

// parse.c
int	parse_argument(t_info *info, int argc, char **argv);

#endif
