/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:36:51 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 18:03:25 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	change_coor(int *x, int *y, int dx, int dy)
{
	*x += dx;
	*y += dy;
}

static t_dot	update_weight(t_dot a, t_dot b)
{
	t_dot	weight;

	weight.x = 1;
	weight.y = 1;
	if (a.x > b.x)
		weight.x = -1;
	if (a.y > b.y)
		weight.y = -1;
	return (weight);
}

static void	small_gradient(t_mlx *mlx, t_dot a, t_dot b, t_dot d)
{
	int		x;
	int		y;
	int		p;
	t_dot	w;

	x = a.x;
	y = a.y;
	p = 2 * d.y - d.x;
	w = update_weight(a, b);
	while (x != b.x || y != b.y)
	{
		print_dot(mlx, y, x);
		if (p < 0)
		{
			p = p + 2 * d.y;
			change_coor(&x, &y, w.x, 0);
		}
		else
		{
			p = p + 2 * (d.y - d.x);
			change_coor(&x, &y, w.x, w.y);
		}
	}
	print_dot(mlx, x, y);
}

static void	big_gradient(t_mlx *mlx, t_dot a, t_dot b, t_dot d)
{
	int		x;
	int		y;
	int		p;
	t_dot	w;

	x = a.x;
	y = a.y;
	p = 2 * d.x - d.y;
	w = update_weight(a, b);
	while (x != b.x || y != b.y)
	{
		print_dot(mlx, y, x);
		if (p < 0)
		{
			p = p + 2 * d.x;
			change_coor(&x, &y, 0, w.y);
		}
		else
		{
			p = p + 2 * (d.x - d.y);
			change_coor(&x, &y, w.x, w.y);
		}
	}
	print_dot(mlx, x, y);
}

void	print_line(t_mlx *mlx, t_dot a, t_dot b)
{
	t_dot	d;

	d.x = abs(a.x - b.x);
	d.y = abs(a.y - b.y);
	if (d.x && d.y / d.x <= 1)
		small_gradient(mlx, a, b, d);
	else
		big_gradient(mlx, a, b, d);
}
