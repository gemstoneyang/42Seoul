/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:18 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/09 22:47:59 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "fdf.h"

void	check_map_name(char *map_name)
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

int	count_width(char *col)
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
t_map   *parse_map_info(char *map_name)
{
	int		fd;
    char    *line;
	int		height;
	int		width;

	width = 0;
	height = 0;
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
		if (width == 0)
			width = count_width(line)
		height++;
    }
	ft_close(fd);
}

void	parse_map(char *map_name)
{
    char    *line;
    char    **split;
    int     fd;

	check_map_name(map_name);
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
        split = ft_split(line, ' ');
        while (*split)
        {
            printf("%s\n", *split);
            split++;
        }
    }
    close(fd); // todo
}

