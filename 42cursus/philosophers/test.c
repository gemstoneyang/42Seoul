/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:41:42 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/31 21:32:53 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

void	*philo(sem_t *fork_sem, int i, int *eat_count)
{
	int			eat_time = 1000;
	int			sleep_time = 1000;

	if (i % 2 == 0)
		usleep(1000);
	while (1)
	{
		sem_wait(fork_sem);
		printf("child %d has taken a fork\n", i);
		sem_wait(fork_sem);
		printf("child %d has taken a fork\n", i);
		printf("child %d is eating\n", i);
		usleep(eat_time * 1000);
		*eat_count += 1;
		sem_post(fork_sem);
		sem_post(fork_sem);
		printf("child %d is sleeping\n", i);
		usleep(sleep_time * 1000);
		printf("child %d is thinking\n", i);
	}
	return (NULL);
}

int	main(void)
{
	int			N = 4;
	sem_t		*eat_sem;
	const char	*eat_sem_name = "/eat_sem";
	sem_t		*fork_sem;
	const char	*fork_sem_name = "/fork_sem";

	fork_sem = sem_open(fork_sem_name, O_CREAT, 0777, 4);
	if (fork_sem == SEM_FAILED)
		return (1);
	if (sem_unlink(fork_sem_name) != 0)
		return (1);

	eat_sem = sem_open(eat_sem_name, O_CREAT, 0777, 4);
	if (eat_sem == SEM_FAILED)
		return (1);
	if (sem_unlink(eat_sem_name) != 0)
		return (1);

	pid_t	*pid_arr;
	int		status;

	pid_arr = (pid_t *)malloc(sizeof(pid_t) * (N + 1));
	for (int i = 1; i < N + 1; i++)
	{
		pid_arr[i] = fork();
		if (pid_arr[i] == -1)
			exit(1);
		if (pid_arr[i] == 0)
		{
			// child
			int eat_count = 0;
			pthread_t	th;

			sem_wait(eat_sem);
			// pthread_create(&th, NULL, philo, NULL);
			// philo(fork_sem, i, &eat_count);
			if (eat_count >= N)
			{
				sem_post(eat_sem);
				pthread_join(th, NULL);
			}
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		waitpid(pid_arr[i], &status, 0);
		printf("child exit status : %d\n", status % 255);
	}

	if (sem_close(fork_sem) != 0)
		return (1);
	return (0);
}
