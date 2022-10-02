/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/02 16:39:45 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	**new_argv;
	char	**new_envp = envp;
	char	**paths;
	char	*new_path;
	char	*cmd_dir;

	argc = 1;
	while (*new_envp)
	{
		if (ft_strnstr(*new_envp, "PATH=", 5))
			break ;
		new_envp++;
	}
	paths = ft_split((*new_envp)+5, ':');
	new_argv = ft_split(argv[1], ' ');
	cmd_dir = ft_strjoin("/", new_argv[0]);
	while (*paths)
	{
		new_path = ft_strjoin(*paths, cmd_dir);
		if (access(new_path, X_OK) == 0)
			break;
		paths++;
		free(new_path);
	}
	if (execve(new_path, new_argv, envp) == -1)
		perror("execve error");
	return (0);
}
