/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/29 14:45:36 by wonyang          ###   ########seoul.kr  */
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
	pthread_mutex_t	print_mutex;
}	t_info;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	uint64_t	last_eat_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread;
	t_info		*info;
}	t_philo;

// init.c
t_fork		*init_fork_arr(int n);
t_philo		*init_philo_arr(t_info *info, t_fork *fork_arr);
void		init_info(t_info *info);

// time.c
uint64_t	get_time(void);
void		pass_time(uint64_t start_time);
void		msleep(uint64_t msec);

// print.c
void		print_log(t_philo *philo, char *msg);

// libft.c
int			ft_atoi(const char *str);

// ft_isinteger.c
int			ft_isinteger(char *str);

// parse.c
int			parse_argument(t_info *info, int argc, char **argv);

#endif
