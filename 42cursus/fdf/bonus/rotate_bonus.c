/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:27 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 15:48:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"
#define _USE_MATH_DEFINES

t_dot	rotate_x(t_dot dot, double theta)
{
	t_dot	new_dot;
	double	rad;

	rad = theta * M_PI / 180;
	new_dot.x = dot.x;
	new_dot.y = round(dot.y * cos(rad) - dot.z * sin(rad));
	new_dot.z = round(dot.y * sin(rad) + dot.z * cos(rad));
	new_dot.color = dot.color;
	return (new_dot);
}

t_dot	rotate_y(t_dot dot, double theta)
{
	t_dot	new_dot;
	double	rad;

	rad = theta * M_PI / 180;
	new_dot.x = round(dot.x * cos(rad) + dot.z * sin(rad));
	new_dot.y = dot.y;
	new_dot.z = round(-dot.x * sin(rad) + dot.z * cos(rad));
	new_dot.color = dot.color;
	return (new_dot);
}

t_dot	rotate_z(t_dot dot, double theta)
{
	t_dot	new_dot;
	double	rad;

	rad = theta * M_PI / 180;
	new_dot.x = round(dot.x * cos(rad) - dot.y * sin(rad));
	new_dot.y = round(dot.x * sin(rad) + dot.y * cos(rad));
	new_dot.z = dot.z;
	new_dot.color = dot.color;
	return (new_dot);
}

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
