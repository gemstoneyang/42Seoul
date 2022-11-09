/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/09 17:00:30 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

typedef struct s_map
{
    int 	height;
    int 	width;
	t_list	*dot_list;
}	t_map;

typedef struct s_dot
{
    int x;
    int y;
    int z;
}	t_dot;

// map.c
void    parse_map(char *map_name);

// ftcntl.c
int		ft_open(const char *path)
void	ft_close(int fd);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

#endif
