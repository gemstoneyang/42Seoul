/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2023/01/01 19:24:47 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdint.h>

typedef struct s_info
{
	int			philo_num;
	int			life_time;
	int			eat_time;
	int			sleep_time;
	int			eat_num;
	uint64_t	start_time;
	sem_t		*fork_sem;
	sem_t		*eat_sem;
	sem_t		*end_sem;
	sem_t		*print_sem;
}	t_info;

typedef struct s_philo
{
	int			id;
	pid_t		pid;
	int			eat_count;
	uint64_t	last_eat_time;
	sem_t		*time_sem;
	t_info		*info;
}	t_philo;

typedef struct s_arg
{
	t_info		*info;
	t_philo		*philo_arr;
}	t_arg;

// init_bonus.c
void		init_arg(t_arg *arg, int argc, char **argv);

// free.c
void		free_arg(t_arg *arg);

// act_bonus.c
void	philo_take_fork(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_put_down_fork(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

// time_bonus.c
uint64_t	get_time(void);
void		ft_usleep(uint64_t time);
void		msleep(uint64_t msec);

// print_bonus.c
int			print_log(t_philo *philo, char *msg);

// sem_bonus.c
sem_t		*init_sem(const char *sem_name, int n);

// ft_isinteger_bonus.c
char		*ft_itoa(int n);
int			ft_isinteger(char *str);

// parse_bonus.c
int			ft_atoi(const char *str);
int			parse_argument(t_info *info, int argc, char **argv);

// util_bonus.c
void		error_exit(const char *msg);
void		*ft_malloc(size_t size);
pid_t		ft_fork(void);

#endif
