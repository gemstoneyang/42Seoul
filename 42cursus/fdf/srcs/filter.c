/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/03 13:51:16 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

t_info	*init_info(t_mlx *mlx, t_map *map)
{
	t_info	*info;
	int		scale;

	mlx = (void *)mlx;
	info = (t_info *)ft_malloc(sizeof(t_info));
	scale = max(1, mlx->win_x / map->width / 4);
	info->xscale = scale;
	info->yscale = scale;
	info->zscale = scale;
	info->xstart = 200 - map->width;
	info->ystart = 600 + map->height / 2;
	return (info);
}

t_dot	dot(t_dot dot, t_info *info)
{
	t_dot	res;

	res.x = info->xscale * dot.x;
	res.y = info->yscale * dot.y;
	res.z = info->zscale * dot.z;
	res = isometric(res);
	res.x += info->xstart;
	res.y += info->ystart;
	res.color = dot.color;
	return (res);
}
