/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/29 23:06:32 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*init_info(void)
{
	t_info	*info;

	info = (t_info *)ft_malloc(sizeof(t_info));
	info->xscale = 2;
	info->yscale = 2;
	info->zscale = 2;
	info->xstart = 100;
	info->ystart = 600;
	info->zstart = 100;
	return (info);
}

t_dot	dot(t_dot *dot, t_info *info)
{
	t_dot	res;

	res.x = info->xscale * dot->x;
	res.y = info->yscale * dot->y;
	res.z = info->zscale * dot->z;
	res = isometric(res);
	res.x += info->xstart;
	res.y += info->ystart;
	res.z += info->zstart;
	return (res);
}
