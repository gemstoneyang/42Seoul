/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/05 01:39:31 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exe(int input_fd, int output_fd, char *cmd, char **envp)
{
	close(STDOUT_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	close(STDIN_FILENO);
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	if (run_execve(cmd, envp) == -1)
		return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	int		infile_fd;
	int		outfile_fd;

	if (argc != 5)
		error_exit("argument error\n");
	if (pipe(fd) == -1)
		perror("pipe error");
	pid = fork();
	if (pid == -1)
		perror("fork error");
	if (pid == 0)
	{
		//child processer
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			perror("open error");
		close(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(STDIN_FILENO);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		if (run_execve(argv[2], envp) == -1)
			return (1);
	}
	else
	{
		//parent processer
		close(fd[1]);
		outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		waitpid(pid, &status, 0);
		run_execve(argv[3], envp);
	}

	return (0);
}
