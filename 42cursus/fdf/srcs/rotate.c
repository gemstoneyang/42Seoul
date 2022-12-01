/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:40 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/01 22:05:37 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
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
