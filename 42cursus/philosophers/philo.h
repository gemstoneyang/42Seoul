/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 20:07:24 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>

typedef struct s_info
{
	int				philo_num;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				eat_num;
	int				is_dead;
	uint64_t		start_time;
	pthread_mutex_t	*print_mutex;
}	t_info;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	uint64_t	last_eat_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	t_info		*info;
}	t_philo;

typedef struct s_arg
{
	t_info		*info;
	t_fork		*fork_arr;
	t_philo		*philo_arr;
	int			error;
}	t_arg;

// init.c
pthread_mutex_t	*init_mutex(void);

// arg.c
int				init_arg(t_arg *arg, int argc, char **argv);
int				free_arg(t_arg *arg);

// act.c
int				philo_take_fork(t_philo *philo, t_fork *fork);
int				philo_eat(t_philo *philo);
int				philo_put_down_fork(t_philo *philo, t_fork *fork);
int				philo_sleep(t_philo *philo);
int				philo_think(t_philo *philo);

// time.c
uint64_t		get_time(void);
void			pass_time(uint64_t start_time);
void			msleep(uint64_t msec);

// print.c
void			print_log(t_philo *philo, char *msg);

// ft_isinteger.c
int				ft_isinteger(char *str);

// parse.c
int				ft_atoi(const char *str);
int				parse_argument(t_info *info, int argc, char **argv);

#endif
