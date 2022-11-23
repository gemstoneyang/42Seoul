/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:57:19 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/23 16:09:32 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "fdf.h"

static t_dot	*init_dot(int x, int y, int z, char *color)
{
	t_dot	*dot;

	dot = (t_dot *)ft_malloc(sizeof(t_dot));
	dot->x = x;
	dot->y = y;
	dot->z = z;
	dot->color = color;
	return (dot);
}

static void	parse_dot(t_map *map_info, char *dot, int x, int y)
{
	char	**split;
	int		z;

	split = ft_split(dot, ',');
	if (!split)
		error_exit("split error");
	if (is_integer(split[0]) == 0)
		error_exit("map value error");
	z = ft_atoi(split[0]);
	(map_info->matrix)[y][x] = init_dot(x, y, z, ft_strdup(split[1]));
	ft_freesplit(split);
}

static void	parse_line(t_map *map_info, char *line, int y)
{
	int		x;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		error_exit("split error");
	x = 0;
	while (split[x])
	{
		parse_dot(map_info, split[x], x, y);
		x++;
	}
	ft_freesplit(split);
}

void	parse_map(t_map *map_info, char *map_name)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
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
		parse_line(map_info, line, y);
		y++;
	}
	ft_close(fd);
}
