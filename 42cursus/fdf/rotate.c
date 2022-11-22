/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:26:40 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/22 17:41:45 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_dot	rotate_x(t_dot dot, double theta)
{
	t_dot	new_dot;

	new_dot.x = dot.x;
	new_dot.y = dot.y * cos(theta) - dot.z * sin(theta);
	new_dot.z = dot.y * sin(theta) + dot.z * cos(theta);
	return (new_dot);
}
