/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:40 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 15:48:57 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#define _USE_MATH_DEFINES

t_dot	isometric(t_dot dot)
{
	t_dot	new_dot;

	new_dot.x = 2 * (dot.y + dot.x);
	new_dot.y = dot.y - dot.x - dot.z;
	new_dot.z = dot.z;
	new_dot.color = dot.color;
	return (new_dot);
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
