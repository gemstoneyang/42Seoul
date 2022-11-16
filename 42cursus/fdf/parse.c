/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:57:19 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 14:17:17 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "fdf.h"

static t_dot	*init_dot(int x, int y, int z, char *color)
{
	t_dot	*dot;

	dot = (t_dot *)malloc(sizeof(t_dot));
	if (!dot)
		error_exit("malloc error");
	dot->x = x;
	dot->y = y;
	dot->z = z;
	dot->color = color;
	return (dot);
}

static void	parse_dot(t_map *map_info, char *dot, int x, int y)
{
	char	**split;
	t_list	*node;
	int		z;

	split = ft_split(dot, ',');
	if (!split)
		error_exit("split error");
	if (is_integer(split[0]) == 0)
		error_exit("map value error");
	z = ft_atoi(split[0]);
	node = ft_lstnew((void *)init_dot(x, y, z, ft_strdup(split[1])));
	if (!node)
		error_exit("list malloc error");
	ft_lstadd_back(&(map_info->dot_list), node);
	ft_freesplit(split);
}

static void	parse_line(t_map *map_info, char *line, int x)
{
	int		y;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		error_exit("split error");
	y = 0;
	while (split[y])
	{
		parse_dot(map_info, split[y], x, y);
		y++;
	}
	ft_freesplit(split);
}

void	parse_map(t_map *map_info, char *map_name)
{
	char	*line;
	int		fd;
	int		x;

	x = 0;
	fd = ft_open(map_name);
	while (1)
	{
		if (get_next_line(&line, fd) == -1)
		{
			ft_close(fd);
			error_exit("gnl error");
		}
		if (!line)
			break ;
		parse_line(map_info, line, x);
		x++;
	}
	ft_close(fd);
}
