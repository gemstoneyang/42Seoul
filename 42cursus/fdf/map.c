/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:18 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 16:48:49 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "fdf.h"

static void	check_map_name(char *map_name)
{
	char	**split;
	int		count;

	split = ft_split(map_name, '.');
	if (!split)
		error_exit("split error");
	count = 0;
	while (split[count])
		count++;
	if (count == 0)
		error_exit("map name error");
	if (ft_strcmp(split[count - 1], "fdf") != 0)
	{
		ft_freesplit(split);
		error_exit("map name error");
	}
	ft_freesplit(split);
}

static int	count_width(char *col)
{
	int		width;
	char	**split;

	split = ft_split(col, ' ');
	if (!split)
		error_exit("split error");
	width = 0;
	while (split[width])
		width++;
	ft_freesplit(split);
	return (width);
}

static t_map	*init_map_info(void)
{
	t_map	*map_info;

	map_info = (t_map *)ft_malloc(sizeof(t_map));
	map_info->height = 0;
	map_info->width = 0;
	map_info->matrix = NULL;
	return (map_info);
}

static void	init_map_matrix(t_map *map)
{
	t_dot	***matrix;
	int		i;

	i = 0;
	matrix = (t_dot ***)ft_malloc(sizeof(t_dot **) * map->height);
	while (i < map->height)
	{
		matrix[i] = (t_dot **)ft_malloc(sizeof(t_dot *) * map->width);
		i++;
	}
	map->matrix = matrix;
}

t_map	*parse_map_info(char *map_name)
{
	int		fd;
	char	*line;
	t_map	*map_info;

	check_map_name(map_name);
	map_info = init_map_info();
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
		if (map_info->width == 0)
			map_info->width = count_width(line);
		map_info->height++;
	}
	ft_close(fd);
	init_map_matrix(map_info);
	return (map_info);
}
