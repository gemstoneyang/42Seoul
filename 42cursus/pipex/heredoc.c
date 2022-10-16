/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:06:42 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/16 21:06:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(char *limiter)
{
	char	*line;
	int		fd;

	fd = open(DUMMY_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror_exit("heredoc open error", 1);
	while (1)
	{
		if (write(0, "pipe heredoc> ", 14) == -1)
			perror_exit("write error", 1);
		if (get_next_line(&line, 0) == -1)
			error_exit("gnl error");
		if (!line)
			break ;
		if (ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) == -1)
			perror_exit("write error", 1);
		free(line);
	}
	return (fd);
}
