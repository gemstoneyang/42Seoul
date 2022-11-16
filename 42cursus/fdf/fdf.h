/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 14:22:56 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

typedef struct s_map
{
	int		height;
	int		width;
	t_list	*dot_list;
}	t_map;

typedef struct s_dot
{
	int		x;
	int		y;
	int		z;
	char	*color;
}	t_dot;

// map.c
t_map	*parse_map_info(char *map_name);

// parse.c
void	parse_map(t_map *map_info, char *map_name);

// ftcntl.c
int		ft_open(const char *path);
void	ft_close(int fd);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

// utils.c
int		is_integer(char *str);

#endif
