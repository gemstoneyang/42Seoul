/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:33:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/28 22:25:42 by wonyang          ###   ########.fr       */
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

	argc = 1;
	while (*new_envp)
	{
		if (ft_strnstr(*new_envp, "PATH=", 5))
			break ;
		new_envp++;
	}
	paths = ft_split(*new_envp, ':');
	while (*paths)
	{
		if (access(*paths, X_OK) == 0)
			break;
		paths++;
	}
	new_argv = ft_split(argv[1], ' ');
	if (execve(*paths, new_argv, envp) == -1)
		perror("execve error");
	printf("%s\n", argv[1]);
	return (0);
}
