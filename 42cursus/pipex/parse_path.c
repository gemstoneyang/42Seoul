/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:12 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/12 18:05:15 by wonyang          ###   ########.fr       */
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

char	*make_cmd_path(char *cmd_name, char **envp)
{
	char	**path_list;
	char	*path;
	int		i;

	if (access(cmd_name, X_OK) == 0)
		return (cmd_name);
	path_list = parse_paths(envp);
	if (!path_list)
		return (NULL);
	i = 0;
	path = NULL;
	while (path_list[i])
	{
		path = join_cmd_path(path_list[i], cmd_name);
		if (!path)
		{
			ft_freesplit(path_list);
			path_list = NULL;
			return (NULL);
		}
		if (chech_path(&path) == 1)
			break ;
		i++;
	}
	ft_freesplit(path_list);
	path_list = NULL;
	return (path);
}
