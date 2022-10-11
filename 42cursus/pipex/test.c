/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/11 22:54:34 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		perror_exit("dup2 error");
	if (close(fd1) == -1)
		perror_exit("close error");
}

pid_t	last_fork(int in_fd, int out_fd, char *cmd, char **envp)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror_exit("fork error");
	if (child_pid == 0)
	{
		ft_dup2(in_fd, STDIN_FILENO);
		ft_dup2(out_fd, STDOUT_FILENO);
		if (run_execve(cmd, envp) == -1)
			error_exit("malloc error");
	}
	return (child_pid);
}

pid_t	fork_child(int *before_fd, char *cmd, char **envp)
{
	int		fd[2];
	pid_t	child_pid;
	int		tmp;

	if (pipe(fd) == -1)
		perror_exit("pipe error");
	tmp = *before_fd;
	*before_fd = fd[0];
	child_pid = fork();
	if (child_pid == -1)
		perror_exit("fork error");
	if (child_pid == 0)
	{
		if (close(fd[0]) == -1)
			perror_exit("close error");
		ft_dup2(tmp, STDIN_FILENO);
		ft_dup2(fd[1], STDOUT_FILENO);
		if (run_execve(cmd, envp) == -1)
			error_exit("malloc error");
	}
	if (close(fd[1]) == -1)
		perror_exit("close error");
	return (child_pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile_fd;
	int		outfile_fd;
	int		before_fd;

	if (argc < 5)
		error_exit("argument error");
	char	*outfile = argv[argc - 1];

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		perror_exit("open error");
	
	before_fd = infile_fd;
	printf("before_fd = %d\n", before_fd);
	int	i = 2;
	pid_t	*child_pids = (pid_t *)malloc(sizeof(pid_t) * argc);
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		perror_exit("open error");
	while (i < argc - 2)
	{
		child_pids[i] = fork_child(&before_fd, argv[i], envp);
		i++;
	}
	child_pids[i] = last_fork(before_fd, outfile_fd, argv[i], envp);

	i = 2;
	while (i < argc - 1)
	{
		waitpid(child_pids[i], NULL, WNOHANG);
		i++;
	}

	return (0);
}
