/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/23 18:24:09 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*init_info(void)
{
	t_info 	*info;

	info = (t_info *)ft_malloc(sizeof(t_info));
	info->xscale = 5;
	info->yscale = 5;
	info->zscale = 5;
	info->xstart = 100;
	info->ystart = 100;
	info->zstart = 100;
	return (info);
}

#include <stdio.h>

t_dot	dot(t_dot *dot, t_info *info)
{
	t_dot	res;

	res.x = info->xscale * dot->x;
	res.y = info->yscale * dot->y;
	res.z = info->zscale * dot->z;
	// res = rotate_x(res, 45);
	// res = rotate_y(res, 30);
	// res = rotate_z(res, 45);
	res = isometric(res);
	res.x += info->xstart;
	res.y += info->ystart;
	res.z += info->zstart;
	return (res);
}
