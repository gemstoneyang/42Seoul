/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/11 20:04:15 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int fd1, int fd2)
{
	printf("- dup running! %d %d\n", fd1, fd2);
	printf("- dup dup2\n");
	if (dup2(fd1, fd2) == -1)
		perror_exit("dup2 error");
	printf("- dup close\n");
	if (close(fd1) == -1)
		perror_exit("close error");
	printf("- dup running finish!\n");
}

pid_t	fork_child(int *before_fd, char *cmd, char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	if (pipe(fd) == -1)
		perror_exit("pipe error");
	child_pid = fork();
	if (child_pid == -1)
		perror_exit("fork error");
	if (child_pid == 0)
	{
		printf("child process start!\n");
		if (close(fd[0]) == -1)
			perror_exit("close error");
		printf("dup start! 1\n");
		ft_dup2(*before_fd, STDIN_FILENO);
		printf("dup start! 2\n");
		ft_dup2(fd[1], STDOUT_FILENO);
		printf("dup finish! 1\n");
		*before_fd = fd[0];
		printf("fd1: %d, fd2: %d, before_fd: %d\n", fd[0], fd[1], *before_fd);
		if (run_execve(cmd, envp) == -1)
			error_exit("malloc error");
	}
	if (close(fd[1]) == -1)
		perror_exit("close error");
	return (child_pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	int		infile_fd;
	int		outfile_fd;

	if (argc < 5)
		error_exit("argument error\n");
	char	*outfile = argv[argc - 1];

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		perror_exit("open error");
	int	before_fd = infile_fd;
	int	i = 2;
	pid_t	*child_pids = (pid_t *)malloc(sizeof(pid_t) * argc);
	while (i < argc - 1)
	{
		printf("%d\n", (int)before_fd);
		child_pids[i] = fork_child(&before_fd, argv[i], envp);
		i++;
	}
	i = 2;
	while (i < argc - 1)
	{
		waitpid(child_pids[i], &status, 0);
		i++;
	}
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		perror_exit("open error");
	outfile_fd = 1;
	ft_dup2(before_fd, outfile_fd);

	return (0);
}
