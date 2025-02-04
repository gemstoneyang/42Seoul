/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:12 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/16 17:29:30 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_cmd_path(char *path, char *cmd)
{
	char	*cmd_dir;
	char	*cmd_path;

	cmd_dir = ft_strjoin("/", cmd);
	if (!cmd_dir)
		return (NULL);
	cmd_path = ft_strjoin(path, cmd_dir);
	free(cmd_dir);
	cmd_dir = NULL;
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}

static char	**parse_paths(char **envp)
{
	char	**paths;

	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			break ;
		envp++;
	}
	if (*envp == NULL)
		return (NULL);
	paths = ft_split((*envp) + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static int	chech_path(char **path)
{
	if (access(*path, X_OK) == 0)
		return (1);
	free(*path);
	*path = NULL;
	return (0);
}

static int	make_path(char **path_list, char *cmd_name, char **path)
{
	int		i;

	i = 0;
	while (path_list[i])
	{
		*path = join_cmd_path(path_list[i], cmd_name);
		if (!(*path))
		{
			ft_freesplit(path_list);
			path_list = NULL;
			return (-1);
		}
		if (chech_path(path) == 1)
			return (0);
		i++;
	}
	return (0);
}

int	make_cmd_path(char *cmd_name, char **path, char **envp)
{
	char	**path_list;

	if (access(cmd_name, X_OK) == 0)
	{
		*path = cmd_name;
		return (0);
	}
	path_list = parse_paths(envp);
	if (!path_list)
		return (-1);
	if (make_path(path_list, cmd_name, path) == -1)
		return (-1);
	ft_freesplit(path_list);
	path_list = NULL;
	return (0);
}
