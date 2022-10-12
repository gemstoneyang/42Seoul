/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:12:54 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/12 21:12:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	run_execve(char *cmd, char **envp)
{
	char	**cmd_argv;
	char	*path;

	cmd_argv = parse_cmd(cmd);
	if (!cmd_argv)
		return (-1);
	path = make_cmd_path(cmd_argv[0], envp);
	if (!path)
	{
		ft_freesplit(cmd_argv);
		cmd_argv = NULL;
		perror("command not found");
		exit(127);
	}
	if (execve(path, cmd_argv, envp) == -1)
	{
		ft_freesplit(cmd_argv);
		cmd_argv = NULL;
		if (!path)
			free(path);
		path = NULL;
		perror_exit("execve error");
	}
	return (-1);
}
