/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:01:25 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/11 20:06:23 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *msg)
{
	perror(msg);
	exit(1);
}

void	error_exit(char *msg)
{
	if (write(2, msg, ft_strlen(msg)) == -1)
		perror_exit("write error");
	if (write(2, "\n", 1) == -1)
		perror_exit("write error");
	exit(1);
}
