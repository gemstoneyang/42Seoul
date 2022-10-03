/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/03 21:46:11 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	/** int		file_fd; */

	if (pipe(fd) == -1)
		perror("pipe error");
	pid = fork();
	if (pid == -1)
		perror("fork error");
	if (pid == 0)
	{
		//child processer
		close(fd[0]);
		dup2(fd[1], 1);
		if (run_execve(argv[1], envp) == -1)
			return (1);
	}
	else
	{
		//parent processer
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, &status, 0);
		run_execve(argv[2], envp);
	}

	argc = 1;
	return (0);
}
