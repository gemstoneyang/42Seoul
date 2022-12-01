/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:01:25 by wonyang           #+#    #+#             */
/*   Updated: 2022/10/29 19:41:29 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	perror_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	error_exit(char *msg)
{
	if (write(2, msg, ft_strlen(msg)) == -1)
		perror_exit("write error", 1);
	if (write(2, "\n", 1) == -1)
		perror_exit("write error", 1);
	exit(1);
}
