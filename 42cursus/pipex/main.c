/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/16 18:05:19 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	infile_fd(char *path)
{
	int	fd;

	if (access(path, R_OK) == -1)
	{
		perror("infile open error");
		fd = open(DUMMY_FILE, O_RDONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			perror_exit("infile open error", 1);
		return (fd);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_exit("infile open error", 1);
	return (fd);
}

static int	outfile_fd(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror_exit("outfile open error", 1);
	return (fd);
}

static void	fork_process(int argc, char **argv, char **envp, pid_t *child_pids)
{
	int		i;
	int		out_fd;
	int		before_fd;

	before_fd = infile_fd(argv[1]);
	out_fd = outfile_fd(argv[argc - 1]);
	i = 2;
	while (i < argc - 2)
	{
		child_pids[i - 2] = fork_child(&before_fd, argv[i], envp);
		i++;
	}
	child_pids[i - 2] = last_fork(before_fd, out_fd, argv[i], envp);
}

static int	wait_process(pid_t *child_pids, int num)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < num)
	{
		waitpid(child_pids[i], &status, 0);
		i++;
	}
	return (status / 256);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	pid_t	*child_pids;

	if (argc < 5)
		error_exit("argument error");
	child_pids = (pid_t *)malloc(sizeof(pid_t) * argc);
	if (!child_pids)
		error_exit("malloc error");
	fork_process(argc, argv, envp, child_pids);
	status = wait_process(child_pids, argc - 2);
	if (access(DUMMY_FILE, F_OK) == 0)
		if (unlink(DUMMY_FILE) == -1)
			perror_exit("unlink error", 1);
	free(child_pids);
	return (status);
}
