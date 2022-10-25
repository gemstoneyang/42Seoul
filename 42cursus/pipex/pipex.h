/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:05:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/26 02:33:05 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define DUMMY_FILE "3ee2fea1-310e-4f54-9483-3227209e0e68"

// parse_path.c
int		make_cmd_path(char *cmd_name, char **path, char **envp);

// execve.c
int		run_execve(char *cmd, char **envp);

// utils.c
char	**parse_cmd(char *cmd);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

// fork.c
pid_t	last_fork(int in_fd, int out_fd, char *cmd, char **envp);
pid_t	fork_child(int *before_fd, char *cmd, char **envp);

// here_doc.c
char	*here_doc(char *limiter);

#endif
