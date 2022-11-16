/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcntl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:02:30 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 14:23:16 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

int	ft_open(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		perror_exit("open error", 1);
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) == -1)
		perror_exit("close error", 1);
}
