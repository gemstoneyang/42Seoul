#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "philo.h"

// 쓰레드 함수
void	*test(void *data)
{
	int	i;
	int *a = (int *)data;

	for (i = 0; i < 10; i++)
	{
		*a += 1;
		printf("%d\n", *a);
	}
	return (NULL);
}

int	main(void)
{
	int a = 100;
	pthread_t thread_t[2];
	int status;

	// 쓰레드 생성
	if (pthread_create(&(thread_t[0]), NULL, test, (void *)&a) < 0)
	{
		perror("thread create error: ");
		exit(0);
	}

	// 쓰레드 생성
	if (pthread_create(&(thread_t[1]), NULL, test, (void *)&a) < 0)
	{
		perror("thread create error: ");
		exit(0);
	}

	// 쓰레드가 종료되기를 기다린 후
	// 쓰레드의 리턴값을 출력한다.
	pthread_join(thread_t[0], (void **)&status);
	pthread_join(thread_t[1], (void **)&status);
	printf("Thread End %d\n", status);
	return (0);
}