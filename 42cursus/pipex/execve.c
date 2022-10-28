/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:12:54 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/28 13:51:24 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_cmd(char *cmd)
{
	char	**cmd_argv;

	cmd_argv = ft_split(cmd, ' ');
	if (!cmd_argv)
		return (NULL);
	return (cmd_argv);
}

int	run_execve(char *cmd, char **envp)
{
	char	**cmd_argv;
	char	*path;

	cmd_argv = parse_cmd(cmd);
	if (!cmd_argv)
		return (-1);
	path = NULL;
	if (make_cmd_path(cmd_argv[0], &path, envp) == -1)
		return (-1);
	if (!path)
	{
		ft_freesplit(cmd_argv);
		cmd_argv = NULL;
		perror_exit("command not found", 127);
	}
	if (execve(path, cmd_argv, envp) == -1)
	{
		ft_freesplit(cmd_argv);
		cmd_argv = NULL;
		if (!path)
			free(path);
		path = NULL;
		perror_exit("execve error", 1);
	}
	return (-1);
}
