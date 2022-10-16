/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:14:58 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/16 17:17:50 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_dup2(int fd1, int fd2)
{
	if (close(fd2) == -1)
		perror_exit("close error", 1);
	if (dup2(fd1, fd2) == -1)
		perror_exit("dup2 error", 1);
	if (close(fd1) == -1)
		perror_exit("close error", 1);
}

pid_t	last_fork(int in_fd, int out_fd, char *cmd, char **envp)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror_exit("fork error", 1);
	if (child_pid == 0)
	{
		ft_dup2(in_fd, STDIN_FILENO);
		ft_dup2(out_fd, STDOUT_FILENO);
		if (run_execve(cmd, envp) == -1)
			error_exit("malloc error");
	}
	if (close(in_fd) == -1)
		perror_exit("close error", 1);
	if (close(out_fd) == -1)
		perror_exit("close error", 1);
	return (child_pid);
}

pid_t	fork_child(int *before_fd, char *cmd, char **envp)
{
	int		fd[2];
	pid_t	child_pid;
	int		tmp;

	if (pipe(fd) == -1)
		perror_exit("pipe error", 1);
	tmp = *before_fd;
	*before_fd = fd[0];
	child_pid = fork();
	if (child_pid == -1)
		perror_exit("fork error", 1);
	if (child_pid == 0)
	{
		if (close(fd[0]) == -1)
			perror_exit("close error", 1);
		ft_dup2(tmp, STDIN_FILENO);
		ft_dup2(fd[1], STDOUT_FILENO);
		if (run_execve(cmd, envp) == -1)
			error_exit("malloc error");
	}
	if (close(tmp) == -1)
		perror_exit("close error", 1);
	if (close(fd[1]) == -1)
		perror_exit("close error", 1);
	return (child_pid);
}
