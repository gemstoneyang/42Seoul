/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:18 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/05 22:24:47 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "fdf.h"
#include "libft/libft.h"

void    parse_map(char *map_name)
{
    char    *line;
    char    **split;
    int     fd;

    fd = open(map_name, O_RDONLY); // todo
    while (1)
    {
        if (get_next_line(&line, fd) == -1)
        {
            close(fd); // todo
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