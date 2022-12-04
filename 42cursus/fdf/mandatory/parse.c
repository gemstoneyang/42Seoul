/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:57:19 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 18:13:25 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

static t_dot	init_dot(int x, int y, int z, char *color)
{
	t_dot	dot;

	dot.x = x;
	dot.y = y;
	dot.z = z;
	dot.color = color;
	return (dot);
}

static void	parse_dot(t_map *map_info, char *dot, int x, int y)
{
	char	**split;
	int		z;

	split = ft_split(dot, ',');
	if (!split)
		ft_error_exit("split error");
	if (ft_isinteger(split[0]) == 0)
		ft_error_exit("map value error");
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
		ft_error_exit("split error");
	x = 0;
	while (split[x])
	{
		parse_dot(map_info, split[x], x, y);
		x++;
	}
	ft_freesplit(split);
}

t_map	*parse_map(char *map_name)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		y;

	map = parse_map_info(map_name);
	fd = ft_open(map_name);
	y = 0;
	while (1)
	{
		if (get_next_line(&line, fd) == -1)
		{
			ft_close(fd);
			ft_error_exit("gnl error");
		}
		if (!line)
			break ;
		parse_line(map, line, y);
		free(line);
		y++;
	}
	ft_close(fd);
	return (map);
}
