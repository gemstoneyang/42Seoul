/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/01 20:25:55 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

// static int	max_height(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	max;

// 	i = 0;
// 	max = 1;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			if (max < abs((map->matrix[i][j]).z))
// 				max = abs((map->matrix[i][j]).z);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (max);
// }

t_info	*init_info(t_mlx *mlx, t_map *map)
{
	t_info	*info;

	info = (t_info *)ft_malloc(sizeof(t_info));
	// info->xscale = mlx->win_width / map->width / 3.5;
	// info->yscale = mlx->win_height / map->height / 5;
	// info->zscale = mlx->win_height / (max_height(map) + map->height) / 2;
	mlx = (t_mlx *)mlx;
	map = (t_map *)map;
	info->xscale = 1;
	info->yscale = 1;
	info->zscale = 3;

	info->xstart = -300;
	info->ystart = 700;
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
	return (res);
}
