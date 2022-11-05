/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/05 22:26:26 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_map
{
    int height;
    int width;
}		t_map;

typedef struct s_dot
{
    int x;
    int y;
    int z;
}		t_dot;

// map.c
void    parse_map(char *map_name);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

#endif
