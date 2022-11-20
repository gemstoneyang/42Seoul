/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 18:10:24 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	*init_info(void)
{
	t_info 	*info;

	info = (t_info *)ft_malloc(sizeof(t_info));
	info->xscale = 50;
	info->yscale = 50;
	info->xstart = 100;
	info->ystart = 100;
	return (info);
}

t_dot	dot(t_dot *dot, t_info *info)
{
	t_dot	res;

	res.x = info->xstart + info->xscale * dot->x;
	res.y = info->ystart + info->yscale * dot->y;
	return (res);
}
