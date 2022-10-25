/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/26 02:35:37 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	infile_fd(char *path)
{
	int	fd;

	if (access(path, R_OK) == -1)
	{
		perror("no infile");
		fd = open(DUMMY_FILE, O_RDONLY | O_CREAT, 0644);
		if (fd == -1)
			perror_exit("infile open error", 1);
		return (fd);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		perror_exit("infile open error", 1);
	return (fd);
}

static int	outfile_fd(char *path, int heredoc)
{
	int	fd;

	if (heredoc == 0)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		perror_exit("outfile open error", 1);
	return (fd);
}

static void	fork_proc(int argc, char **argv, char **envp, pid_t *pids)
{
	int		i;
	int		out_fd;
	int		before_fd;
	int		count;

	i = 2;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		before_fd = infile_fd(here_doc(argv[2]));
		out_fd = outfile_fd(argv[argc - 1], 1);
		i++;
	}
	else
	{
		before_fd = infile_fd(argv[1]);
		out_fd = outfile_fd(argv[argc - 1], 0);
	}
	count = 0;
	while (i < argc - 2)
	{
		pids[count] = fork_child(&before_fd, argv[i], envp);
		i++;
		count++;
	}
	pids[count] = last_fork(before_fd, out_fd, argv[i], envp);
}

static int	wait_proc(pid_t *child_pids, int num)
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
	fork_proc(argc, argv, envp, child_pids);
	status = wait_proc(child_pids, argc - 2);
	if (access(DUMMY_FILE, F_OK) == 0)
		if (unlink(DUMMY_FILE) == -1)
			perror_exit("unlink error", 1);
	free(child_pids);
	return (status);
}
